/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:06:43 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/05 10:58:11 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	echo_print(t_command *cmd, int *nl)
{
	int			index;
	int			options;

	if (!cmd->args || !cmd->args[0])
		return ;
	index = 0;
	options = 1;
	while (cmd->args[index])
	{
		if (options)
		{
			if (cmd->args[index][0] == '-' && ft_strchr(cmd->args[index], 'n'))
				*nl = 0;
			else
				options = 0;
		}
		if (!options)
		{
			printf("%s", cmd->args[index]);
			if (cmd->args[index + 1])
				printf(" ");
		}
		index++;
	}
	return ;
}

void	execute_echo(t_execution *exec)
{
	t_command	*cmd;
	int			nl;

	nl = 1;
	cmd = exec->current->content;
	echo_print(cmd, &nl);
	if (nl)
		printf("\n");
	g_global = 0;
}
