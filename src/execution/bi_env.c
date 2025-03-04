/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:04:35 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/03 16:16:06 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	execute_env(t_execution *exec)
{
	t_list	*node;

	execute_redirs(exec->current->content);
	node = *exec->envp;
	while (node)
	{
		if (node->content && ft_strchr((char *)node->content, '='))
			printf("%s\n", (char *)node->content);
		node = node->next;
	}
}
