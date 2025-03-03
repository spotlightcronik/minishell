/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:28:07 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/03 12:21:27 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	update_pwd(t_execution *exec)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	ft_setenv(exec->envp, "HOME", pwd);
	free(pwd);
}

static void	cd_home(t_execution *exec)
{
	t_list	*node;
	char	*value;

	node = ft_envp_node(exec->envp, "HOME");
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

static void	cd_path(t_execution *exec)
{
	t_command	*cmd;

	cmd = exec->current->content;
	if (cmd->args[2])
	{
		g_global = 3;
		ft_fprintf(2, "minishell: cd: too manu arguments\n");
		return ;
	}
	chdir(cmd->args[1]);
	update_pwd(exec);
	g_global = 0;
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
