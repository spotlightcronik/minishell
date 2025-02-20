/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:28:07 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/20 15:57:17 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static char	*add_pwd(char *current, char *splitted)
{
	char	*placeholder;

	if (!current)
		return (NULL);
	if (!ft_strcmp(splitted, "."))
		return (current);
	if (!ft_strcmp(splitted, ".."))
	{
		if (!ft_strcmp(current, "/"))
			return (current);
		placeholder = ft_substr(current, 0, ft_strrchr(current, '/') - current);
		free(current);
		return (placeholder);
	}
	placeholder = ft_freejoin(ft_strjoin(current, "/"), splitted);
	free(current);
	return (placeholder);
}

static void	change_pwd_relative(t_command *cmd, t_list *envp)
{
	char	*placeholder;
	char	**splitted;
	int		index;

	placeholder = ft_strdup(ft_getenv(envp, "PWD"));
	if (!placeholder)
		return ;
	splitted = ft_split(cmd->args[0], '/');
	if (!splitted)
	{
		free(placeholder);
		return ;
	}
	index = -1;
	while (splitted[++index])
		placeholder = add_pwd(placeholder, splitted[index]);
	index = -1;
	while (splitted[++index])
		free(splitted[index]);
	free(splitted);
	if (placeholder)
		ft_setenv(envp, "PWD", placeholder);
	free(placeholder);
}

static void	change_pwd(t_execution *exec)
{
	t_command	*cmd;

	cmd = exec->current->content;
	if (!cmd->args)
		ft_setenv(exec->envp, "PWD", ft_getenv(exec->envp, "HOME"));
	else if (cmd->args[0][0] == '/')
		ft_setenv(exec->envp, "PATH", cmd->args[0]);
	else
		change_pwd_relative(cmd, exec->envp);
}

void	execute_cd(t_execution *exec)
{
	t_command	*cmd;
	int			ret;

	cmd = exec->current->content;
	if (cmd->args)
		ret = chdir(cmd->args[0]);
	else
		ret = chdir(ft_getenv(exec->envp, "HOME"));
	if (ret != 0)
	{
		if (!cmd->args)
			ft_fprintf(2, "cd: HOME not set");
		if (cmd->args)
		{
			if (access(cmd->args[0], F_OK) != 0)
				ft_fprintf(2, "cd: Path not found");
			else if (access(cmd->args[0], X_OK) != 0)
				ft_fprintf(2, "cd: Permission denied");
		}
	}
	else
		change_pwd(exec);
}
