/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:13:54 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/03 12:14:29 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static char	*absolute_path(char *path)
{
	struct stat	info;

	if (access(path, F_OK) == -1)
	{
		ft_fprintf(2, "minishell: Command not found.\n");
		return (NULL);
	}
	if (access(path, X_OK) == -1)
	{
		ft_fprintf(2, "minishell: Permission denied.\n");
		return (NULL);
	}
	stat(path, &info);
	if (S_ISDIR(info.st_mode))
	{
		ft_fprintf(2, "minishell: Is a directory.\n");
		return (NULL);
	}
	return (path);
}

static char	*check_cmd_path(char **split_path, char *cmd_name)
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

char	*alias_path(t_command *cmd, t_list *ep_lst)
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
	{
		ft_fprintf(2, "minishell: malloc error\n");
		return (NULL);
	}
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

char	*get_cmd_path(t_command *cmd, t_list *ep_lst)
{
	char	*path;

	if (cmd->name[0] == '.' || cmd->name[0] == '/')
		return (absolute_path(cmd->name));
	else
	{
		path = alias_path(cmd, ep_lst);
		if (!path)
			ft_fprintf(2, "minishell: Command not found.\n");
		return (path);
	}
}
