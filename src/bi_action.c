/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:15:02 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/06 16:28:00 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	execute_unset(t_command *cmd, t_list *envp)
{
	int		index;
	t_list	*node;

	index = 0;
	while (cmd->args[index])
	{
		node = ft_envp_node(envp, cmd->args[index]);
		if (node)
			ft_lstdelone(ft_lstdetach(&envp, node), free);
		index++;
	}
}
