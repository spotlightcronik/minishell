/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_routing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:35:27 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/25 12:01:34 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	multiple_cmd(t_execution *exec)
{
	t_pipe	pipe_bundle[2];

	while (exec->current)
	{
		if (exec->index + 1 != exec->size)
			pipe(pipe_bundle[0]);
		if (exec->index == 0)
			ft_fork(exec, 0, pipe_bundle[0][1]);
		else if (exec->index != exec->size - 1)
			ft_fork(exec, pipe_bundle[1][0],
				pipe_bundle[0][1]);
		else
			ft_fork(exec, pipe_bundle[1][0], 1);
		close(pipe_bundle[0][1]);
		if (exec->index)
			close(pipe_bundle[1][0]);
		pipe_bundle[1][0] = pipe_bundle[0][0];
		exec->index++;
		exec->current = exec->current->next;
	}
	close(pipe_bundle[1][0]);
}

void	parse_to_exec(t_execution *exec, t_list *cmds, t_list *envp)
{
	ft_bzero(exec, sizeof(t_execution));
	exec->cmds = cmds;
	exec->envp = envp;
	exec->current = exec->cmds;
	exec->size = ft_lstsize(exec->cmds);
}

void	execute_line(t_list *lst, t_list *envp)
{
	t_execution	exec;
	int			wstatus;

	if (!lst || !lst->content)
		return ;
	parse_to_exec(&exec, lst, envp);
	if (exec.size == 1)
		ft_fork(&exec, 0, 1);
	else
		multiple_cmd(&exec);
	if (!exec.pid)
		return ;
	waitpid(exec.pid, &wstatus, 0);
	if (WIFEXITED(wstatus))
		g_global = WEXITSTATUS(wstatus);
}
