/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:59:19 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/27 18:00:27 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	execute_unset(t_execution *exec)
{
	t_command	*cmd;
	int			index;
	t_list		*node;

	index = 0;
	cmd = exec->current->content;
	if (cmd->args)
	{
		while (cmd->args[index])
		{
			node = ft_envp_node(exec->envp, cmd->args[index]);
			if (node)
				ft_lstdelone(ft_lstdetach(&exec->envp, node), free);
			index++;
		}
	}
	g_global = 0;
}
