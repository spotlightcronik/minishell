/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:41:40 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/25 15:53:29 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	execute_printbi(t_execution *exec, t_fd in, t_fd out)
{
	t_command	*cmd;
	t_fd		prev[2];

	cmd = exec->current->content;
	prev[0] = dup(STDIN_FILENO);
	dup2(in, STDIN_FILENO);
	if (in != STDIN_FILENO)
		close(in);
	prev[1] = dup(STDOUT_FILENO);
	dup2(in, STDOUT_FILENO);
	if (out != STDOUT_FILENO)
		close(out);
	if (!ft_strcmp(cmd->name, "echo"))
		execute_echo(exec);
	else if (!ft_strcmp(cmd->name, "pwd"))
		execute_pwd(exec);
	else if (!ft_strcmp(cmd->name, "env"))
		execute_env(exec);
	dup2(prev[0], STDIN_FILENO);
	dup2(prev[1], STDIN_FILENO);
}

static void	execute_actionbi(t_execution *exec)
{
	t_command	*cmd;

	cmd = exec->current->content;
	if (!ft_strcmp(cmd->name, "cd"))
		execute_cd(exec);
	else if (!ft_strcmp(cmd->name, "export"))
		execute_export(exec);
	else if (!ft_strcmp(cmd->name, "unset"))
		execute_unset(exec);
	else if (!ft_strcmp(cmd->name, "exit"))
		execute_exit(exec);
}

void	execute_builtin(t_execution *exec, t_fd in, t_fd out)
{
	t_command	*cmd;

	cmd = exec->current->content;
	if (!ft_strcmp(cmd->name, "echo") || !ft_strcmp(cmd->name, "pwd")
		|| !ft_strcmp(cmd->name, "env"))
		execute_printbi(exec, in, out);
	else
		execute_actionbi(exec);
}
