/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:06:43 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/03 19:14:29 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	echo_print(t_command *cmd)
{
	int			index;
	int			nl;

	if (!cmd->args[0])
		return (1);
	index = 0;
	nl = 1;
	if (!ft_strcmp(cmd->args[0], "-n"))
	{
		index++;
		nl = 0;
	}
	while (cmd->args[index])
	{
		printf("%s", cmd->args[index]);
		index++;
		if (cmd->args[index])
			printf(" ");
	}
	return (nl);
}

void	execute_echo(t_execution *exec)
{
	t_command	*cmd;
	int			nl;

	nl = 1;
	cmd = exec->current->content;
	if (execute_redirs(cmd) == -1)
	{
		g_global = 1;
		return ;
	}
	if (cmd->args)
	{
		nl = echo_print(cmd);
	}
	if (nl)
		printf("\n");
	g_global = 0;
}
