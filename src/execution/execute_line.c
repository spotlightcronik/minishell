/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:35:27 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/05 13:11:57 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	multiple_cmd(t_execution *exec)
{
	t_fd	pipe_fd[3];

	while (exec->current)
	{
		if (exec->index + 1 != exec->size)
			if (pipe(pipe_fd) == -1)
				return (-1);
		if (exec->index == 0)
			ft_fork(exec, 0, pipe_fd[1]);
		else if (exec->index != exec->size - 1)
			ft_fork(exec, pipe_fd[2], pipe_fd[1]);
		else
			ft_fork(exec, pipe_fd[2], 1);
		if (exec->index + 1 != exec->size)
			close(pipe_fd[1]);
		if (exec->index)
			close(pipe_fd[2]);
		pipe_fd[2] = pipe_fd[0];
		exec->index++;
		exec->current = exec->current->next;
	}
	return (0);
}

static int	validate_cmds(t_execution *exec)
{
	t_list		*lst;
	t_command	*cmd;

	lst = exec->current;
	while (lst)
	{
		cmd = lst->content;
		if (!cmd->name)
		{
			ft_fprintf(2, "minishell: no command found\n");
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

static int	execute_init(t_execution *exec, t_list *lst, t_list **envp)
{
	if (!lst || !lst->content)
		return (-1);
	signals_exec();
	ft_bzero(exec, sizeof(t_execution));
	exec->cmds = lst;
	exec->envp = envp;
	exec->current = exec->cmds;
	exec->size = ft_lstsize(exec->cmds);
	if (validate_cmds(exec))
		return (-1);
	if (heredoc_manager(exec) == -1)
		return (-1);
	signals_exec();
	return (0);
}

void	execute_line(t_list *lst, t_list **envp)
{
	t_execution	exec;
	int			wstatus;

	wstatus = 0;
	if (execute_init(&exec, lst, envp))
		return ;
	if (exec.size == 1)
		ft_fork(&exec, 0, 1);
	else
		multiple_cmd(&exec);
	if (exec.pid)
	{
		waitpid(exec.pid, &wstatus, 0);
		if (WIFEXITED(wstatus))
			g_global = WEXITSTATUS(wstatus);
		else if (WIFSIGNALED(wstatus))
			g_global = WTERMSIG(wstatus) + 128;
	}
	clean_heredoc(exec);
	kill(0, SIGQUIT);
}
