/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:38:34 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/25 11:11:17 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

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
		index = -1;
		while (cmd->args[++index])
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

static char	*check_cmd_path(char **split_path, char *cmd_name)
{
	int		index;
	char	*cmd_path;

	if (access(cmd_name, X_OK) == 0)
		return (cmd_name);
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
	char	*full_cmd;
	char	*path;
	char	**splitted;
	int		index;

	path = ft_getenv(ep_lst, "PATH");
	if (!path)
		return (NULL);
	splitted = ft_split(path, ':');
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

void	execute_cmd(t_execution *exec)
{
	char		*cmd_path;
	char		**args;
	char		**envp;

	prepare_exec(exec->current->content);
	cmd_path = get_cmd_path(exec->current->content, exec->envp);
	if (!cmd_path)
	{
		ft_lstclear(&exec->envp, free);
		ft_lstclear(&exec->cmds, free_cmd);
		perror("Command not found");
		exit(127);
	}
	args = prepare_args(exec->current->content);
	envp = (char **)ft_lsttoarr(exec->envp);
	if (execve(cmd_path, args, envp) == -1)
	{
		perror("execve failed");
		exit(128);
	}
}
