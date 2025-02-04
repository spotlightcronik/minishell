/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:04:35 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/04 15:15:43 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static pipe_t	*prepare_pipes(int size)
{
	pipe_t	*pipe_bundle;
	int		index;
	
	pipe_bundle = ft_calloc(size, sizeof(pipe_t));
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

static char	**prepare_args(t_command *cmd)
{
	char	**args;
	int		index;

	index = 0;
	if (cmd->args)
	{
		while (cmd->args[index])
			index++;
		args = ft_calloc(index + 2, sizeof(char *));
		if (!args)
			return (NULL);
		args[0] = cmd->name;
		index = 0;
		while (cmd->args[index])
			args[index + 1] = cmd->args[index];
	}
	else
	{
		args = ft_calloc(index + 2, sizeof(char *));
		if (!args)
			return (NULL);
		args[0] = cmd->name;
	}
	return (args);
}

static int	handler(void *s1, void *s2)
{
	return (ft_strncmp(s1, s2, ft_strlen(s2)));
}

static char *check_cmd_path(char **split_path, char *cmd_name)
{
	int		index;
	char	*cmd_path;

	index = 0;
	while (split_path[index])
	{
		cmd_path = ft_freejoin(ft_strjoin(split_path[index], "/"), cmd_name);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		index++;
	}
	return (NULL);
}

static char	*get_cmd_path(t_command *cmd, t_list *ep_lst)
{
	t_list	*node;
	char	*full_cmd;
	char	*path;
	char	**splitted;
	int		index;

	node = ft_lstchr(ep_lst, "PATH", handler);
	if (!node)
		return (NULL);
	path = node->content;
	splitted = ft_split(path + 5, ':');
	if (!splitted)
		return (NULL);
	full_cmd = check_cmd_path(splitted, cmd->name);
	index = 0;
	while (splitted[index])
	{
		free(splitted[index]);
		index++;
	}
	free(splitted);
	return (full_cmd);
}

static void	execute_cmd(t_command *cmd, t_list *ep_lst)
{
	t_execution	exec;
	char		*cmd_path;
	char		**args;
	char		**envp;

	prepare_exec(*cmd, &exec);
	cmd_path = get_cmd_path(cmd, ep_lst);
	args = prepare_args(cmd);
	envp = (char **)ft_lsttoarr(ep_lst);
	if (execve(cmd_path, args, envp) == -1)
	{
		exit(1);
	}
}

static pid_t	ft_fork(t_command *cmd, fd_t in, fd_t out, t_list *envp)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		dup2(in, STDIN_FILENO);
		dup2(out, STDOUT_FILENO);
		execute_cmd(cmd, envp);
	}
	return (pid);
}

static pid_t	multiple_cmd(t_list *lst, int size, t_list *envp)
{
	pid_t	pid;
	pipe_t	*pipe_bundle;
	int		index;

	pipe_bundle = prepare_pipes(size);
	index = 0;
	while (lst)
	{
		if (index == 0)
			pid = ft_fork(lst->content, 0, pipe_bundle[0][1], envp);
		else if (index != size - 1)
			pid = ft_fork(lst->content, pipe_bundle[index - 1][0], pipe_bundle[index][1], envp);
		else
			pid = ft_fork(lst->content, pipe_bundle[index - 1][0], 1, envp);
		close(pipe_bundle[index][1]);
		if (index != 1)
			close(pipe_bundle[index - 1][0]);
		index++;
		lst = lst->next;
	}
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
	waitpid(pid, NULL, 0);
	ft_lstiter(lst, free_cmd);
}
