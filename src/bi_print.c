/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:04:35 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/21 11:17:00 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	execute_echo(t_execution *exec)
{
	t_command	*cmd;
	int			index;
	int			nl;

	cmd = exec->current->content;
	if (ft_strcmp(cmd->name, "echo"))
		return ;
	index = -1;
	nl = 1;
	if (cmd->args)
	{
		if (!ft_strcmp(cmd->args[++index], "-n"))
		{
			index++;
			nl = 0;
		}
		while (cmd->args[++index])
		{
			printf("%s", cmd->args[index]);
			if (cmd->args[index + 1])
				printf(" ");
		}
	}
	if (nl)
		printf("\n");
}

void	execute_pwd(t_execution *exec)
{
	char	*pwd;

	prepare_exec(exec->current->content);
	pwd = ft_getenv(exec->envp, "PWD");
	if (!pwd)
		return ;
	printf("%s\n", pwd);
}

void	execute_env(t_execution *exec)
{
	t_list	*node;

	prepare_exec(exec->current->content);
	node = exec->envp;
	while (node)
	{
		if (node->content && *(ft_strchr((char *)node->content, '=')))
			printf("%s\n", (char *)node->content);
		node = node->next;
	}
}
