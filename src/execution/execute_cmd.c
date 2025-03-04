/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:38:34 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/03 16:17:10 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static char	**prepare_args(t_command *cmd)
{
	char	**args;
	int		index;

	if (cmd->args)
	{
		index = 0;
		while (cmd->args[index])
			index++;
		args = ft_calloc(index + 2, sizeof(char *));
		if (!args)
			return (NULL);
		args[0] = cmd->name;
		while (index--)
			args[index + 1] = cmd->args[index];
	}
	else
	{
		args = ft_calloc(2, sizeof(char *));
		if (!args)
			return (NULL);
		args[0] = cmd->name;
	}
	return (args);
}

void	execute_cmd(t_execution *exec)
{
	char		*cmd_path;
	char		**args;
	char		**envp;

	if (execute_redirs(exec->current->content) == -1)
		exit(126);
	cmd_path = get_cmd_path(exec->current->content, *exec->envp);
	if (!cmd_path)
	{
		ft_lstclear(exec->envp, free);
		ft_lstclear(&exec->cmds, free_cmd);
		exit(127);
	}
	args = prepare_args(exec->current->content);
	envp = (char **)ft_lsttoarr(*exec->envp);
	if (execve(cmd_path, args, envp) == -1)
	{
		ft_lstclear(exec->envp, free);
		ft_lstclear(&exec->cmds, free_cmd);
		ft_fprintf(2, "minishell: execve failed\n");
		exit(128);
	}
}
