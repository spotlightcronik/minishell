/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:33:01 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/27 17:29:05 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	free_redir(t_token	*redir)
{
	int			index;
	
	index = 0;
	while (redir[index].type)
	{
		free(redir[index].type);
		free(redir[index].content);
		index++;
	}
	free(redir);
}

void	free_cmd(void *ptr)
{
	int			index;
	t_command	*cmd;

	cmd = ptr;
	if (cmd)
	{
		if (cmd->redir)
			free_redir(cmd->redir);
		if (cmd->name)
			free(cmd->name);
		if (cmd->args)
		{
			index = 0;
			while (cmd->args[index])
			{
				free(cmd->args[index]);
				index++;
			}
			free(cmd->args);
		}
		free(cmd);
	}
}
