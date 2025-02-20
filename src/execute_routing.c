/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_routing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:35:27 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/20 15:47:53 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static t_pipe	*prepare_pipes(int size)
{
	t_pipe	*pipe_bundle;
	int		index;

	pipe_bundle = ft_calloc(size - 1, sizeof(t_pipe));
	if (!pipe_bundle)
		return (NULL);
	index = 0;
	while (index < size - 1)
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

static void	multiple_cmd(t_execution *exec)
{
	t_pipe	*pipe_bundle;

	pipe_bundle = prepare_pipes(exec->size);
	if (!pipe_bundle)
		return ;
	while (exec->current)
	{
		if (exec->index == 0)
			ft_fork(exec, 0, pipe_bundle[0][1]);
		else if (exec->index != exec->size - 1)
			ft_fork(exec, pipe_bundle[exec->index - 1][0], pipe_bundle[exec->index][1]);
		else
			ft_fork(exec, pipe_bundle[exec->index - 1][0], 1);
		close(pipe_bundle[exec->index][1]);
		if (exec->index)
			close(pipe_bundle[exec->index - 1][0]);
		exec->index++;
		exec->current = exec->current->next;
	}
	close(pipe_bundle[exec->index - 1][0]);
	free(pipe_bundle);
}

void	parse_to_exec(t_execution *exec, t_list *cmds, t_list *envp)
{
	ft_bzero(exec, sizeof(exec));
	exec->cmds = cmds;
	exec->envp = envp;
	exec->current = exec->cmds;
	exec->size = ft_lstsize(exec->cmds);
}

void	execute_line(t_list *lst, t_list *envp)
{
	t_execution	exec;

	if (!exec.cmds)
		return ;
	parse_to_exec(&exec, lst, envp);
	if (exec.size == 1)
		ft_fork(&exec, 0, 1);
	else
		multiple_cmd(&exec);
	if (exec.exit)
		//to-do
	if (exec.pid)
		waitpid(exec.pid, NULL, 0);
}
