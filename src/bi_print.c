/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:04:35 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/06 16:16:09 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	execute_echo(t_command *cmd)
{
	int	index;
	int	nl;

	if (ft_strcmp(cmd->name, "echo"))
		return ;
	index = 0;
	nl = 1;
	if (!ft_strcmp(cmd->args[index], "-n"))
	{
		index++;
		nl = 0;
	}
	while (cmd->args[index])
	{
		printf("%s", cmd->args[index]);
		index++;
		if (!cmd->args[index])
			printf(" ");
	}
	if (nl)
		printf("\n");
}

void	execute_pwd(t_command *cmd, t_list *envp)
{
	char	*pwd;

	pwd = ft_getenv(envp, "PWD");
	if (!pwd)
		return ;
	ft_printf("%s\n", pwd);
}

void	execute_env(t_command *cmd, t_list *envp)
{
	t_list	*node;

	node = envp;
	while (node)
	{
		if (node->content)
			printf("%s\n", node->content);
		node = node->next;
	}
}
