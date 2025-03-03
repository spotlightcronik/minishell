/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:11:39 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/03 15:44:49 by jeperez-         ###   ########.fr       */
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

int	ft_fork(t_execution *exec, t_fd in, t_fd out)
{
	t_command	*cmd;

	cmd = exec->current->content;
	if (!is_builtin(cmd->name))
	{
		exec->pid = fork();
		if (!exec->pid)
		{
			if (ft_dup2(in, STDIN_FILENO) == -1)
				return (-1);
			if (ft_dup2(out, STDOUT_FILENO) == -1)
				return (-1);
			execute_cmd(exec);
		}
	}
	else
		execute_builtin(exec, in, out);
	return (0);
}
