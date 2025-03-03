/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:28:07 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/03 19:13:39 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	update_pwd(t_execution *exec)
{
	char	*pwd;
	char	*old;

	pwd = getcwd(NULL, 0);
	old = ft_getenv(*exec->envp, "PWD");
	if (old)
		ft_setenv(exec->envp, "OLDPWD", ft_strchr(old, '=') + 1);
	ft_setenv(exec->envp, "PWD", pwd);
	free(pwd);
}

static void	cd_home(t_execution *exec)
{
	t_list	*node;
	char	*value;

	node = ft_envp_node(*exec->envp, "HOME");
	if (!node)
	{
		g_global = 1;
		ft_fprintf(2, "minishell: cd: HOME is not set\n");
		return ;
	}
	value = ft_strchr(node->content, '=');
	if (!value)
	{
		g_global = 2;
		ft_fprintf(2, "minishell: cd: HOME is not defined\n");
		return ;
	}
	chdir(value + 1);
	update_pwd(exec);
	g_global = 0;
}

static void	cd_path2(t_execution *exec)
{
	DIR			*fd;
	t_command	*cmd;

	cmd = exec->current->content;
	fd = opendir(cmd->args[0]);
	if (fd == NULL)
	{
		g_global = 6;
		ft_fprintf(2, "minishell: cd: not a directory\n");
		return ;
	}
	closedir(fd);
	chdir(cmd->args[0]);
	update_pwd(exec);
	g_global = 0;
}

static void	cd_path(t_execution *exec)
{
	t_command	*cmd;

	cmd = exec->current->content;
	if (cmd->args[1])
	{
		g_global = 3;
		ft_fprintf(2, "minishell: cd: too many arguments\n");
		return ;
	}
	if (access(cmd->args[0], F_OK) == -1)
	{
		g_global = 4;
		ft_fprintf(2, "minishell: cd: file not found\n");
		return ;
	}
	if (access(cmd->args[0], X_OK) == -1)
	{
		g_global = 5;
		ft_fprintf(2, "minishell: cd: permission denied\n");
		return ;
	}
	cd_path2(exec);
}

void	execute_cd(t_execution *exec)
{
	t_command	*cmd;

	cmd = exec->current->content;
	if (!cmd->args || !cmd->args[0])
		cd_home(exec);
	else
		cd_path(exec);
}
