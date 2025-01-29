/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:13:10 by jeperez-          #+#    #+#             */
/*   Updated: 2024/12/13 11:19:20 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstinsert(t_list *node, t_list *insert)
{
	insert->next = node->next;
	insert->prev = node;
	if (node->next)
		node->next->prev = insert;
	node->next = insert;
	return (insert);
}
