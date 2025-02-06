/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_routing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:35:27 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/06 15:40:58 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	is_builtin(char *cmd_name)
{
	if (!ft_strcmp(cmd_name, "echo"))
		return (1);
	if (!ft_strcmp(cmd_name, "cd"))
		return (1);
	if (!ft_strcmp(cmd_name, "pwd"))
		return (1);
	if (!ft_strcmp(cmd_name, "export"))
		return (1);
	if (!ft_strcmp(cmd_name, "unset"))
		return (1);
	if (!ft_strcmp(cmd_name, "env"))
		return (1);
	if (!ft_strcmp(cmd_name, "exit"))
		return (1);
	return (0);
}

static pid_t	ft_fork(t_command *cmd, t_fd in, t_fd out, t_list *envp)
{
	pid_t	pid;

	if (!is_builtin(cmd->name))
	{
		pid = fork();
		if (!pid)
		{
			dup2(in, STDIN_FILENO);
			if (in != STDIN_FILENO)
				close(in);
			dup2(out, STDOUT_FILENO);
			if (out != STDOUT_FILENO)
				close(out);
			execute_cmd(cmd, envp);
		}
	}
	else
		pid = execute_builtin(cmd, in, out, envp);
	return (pid);
}

static t_pipe	*prepare_pipes(int size)
{
	t_pipe	*pipe_bundle;
	int		index;

	pipe_bundle = ft_calloc(size, sizeof(t_pipe));
	if (!pipe_bundle)
		return (NULL);
	index = 0;
	while (index < size)
	{
		if (pipe(pipe_bundle[index]) == -1)
		{
			free(pipe_bundle);
			return (NULL);
		}
		index++;
	}
	return (pipe_bundle);
}

static pid_t	multiple_cmd(t_list *lst, int size, t_list *envp)
{
	pid_t	pid;
	t_pipe	*pipe_bundle;
	int		index;

	pipe_bundle = prepare_pipes(size);
	index = 0;
	while (lst)
	{
		if (index == 0)
			pid = ft_fork(lst->content, 0, pipe_bundle[0][1], envp);
		else if (index != size - 1)
			pid = ft_fork(lst->content, pipe_bundle[index - 1][0],
					pipe_bundle[index][1], envp);
		else
			pid = ft_fork(lst->content, pipe_bundle[index - 1][0], 1, envp);
		close(pipe_bundle[index][1]);
		if (index)
			close(pipe_bundle[index - 1][0]);
		index++;
		lst = lst->next;
	}
	close(pipe_bundle[index - 1][0]);
	free(pipe_bundle);
	return (pid);
}

void	execute_line(t_list *lst, t_list *envp)
{
	pid_t	pid;
	int		size;

	if (!lst)
		return ;
	size = ft_lstsize(lst);
	if (size == 1)
		pid = ft_fork(lst->content, 0, 1, envp);
	else
		pid = multiple_cmd(lst, size, envp);
	if (pid)
		waitpid(pid, NULL, 0);
}
