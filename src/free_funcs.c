/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:33:01 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/04 12:50:09 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	free_cmd(void *ptr)
{
	int	index;
	t_command *cmd;

	cmd = ptr;
	if (cmd)
	{
		if (cmd->infile)
			free(cmd->infile);
		if (cmd->name)
			free(cmd->name);
		if (cmd->args)
		{
			index = 0;
			while (cmd->args[index])
			{
				free(cmd->infile);
				index++;
			}
		}
		if (cmd->outfile)
			free(cmd->outfile);
		free(cmd);
	}
}
