/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:41:40 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/06 16:16:20 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static pid_t	execute_printbi(t_command *cmd, t_fd in, t_fd out, t_list *envp)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		dup2(in, STDIN_FILENO);
		if (in != STDIN_FILENO)
			close(in);
		dup2(out, STDOUT_FILENO);
		if (out != STDOUT_FILENO)
			close(out);
		if (!ft_strcmp(cmd->name, "echo"))
			execute_echo(cmd);
		else if (!ft_strcmp(cmd->name, "pwd"))
			execute_pwd(cmd, envp);
		else if (!ft_strcmp(cmd->name, "env"))
			execute_env(cmd, envp);
		exit(0);
	}
	return (pid);
}

static void	execute_actionbi(t_command *cmd, t_list *envp)
{
	if (!ft_strcmp(cmd->name, "cd"))
		execute_cd(cmd, envp);
	else if (!ft_strcmp(cmd->name, "export"))
		execute_export(cmd, envp);
	else if (!ft_strcmp(cmd->name, "unset"))
		execute_unset(cmd, envp);
	else if (!ft_strcmp(cmd->name, "exit"))
		execute_exit(cmd, envp);
}

pid_t	execute_builtin(t_command *cmd, t_fd in, t_fd out, t_list *envp)
{
	if (!ft_strcmp(cmd->name, "echo") || !ft_strcmp(cmd->name, "pwd")
		|| !ft_strcmp(cmd->name, "env"))
		return (execute_printbi(cmd, in, out, envp));
	else
		execute_actionbi(cmd, envp);
	return (0);
}
