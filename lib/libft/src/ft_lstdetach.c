/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdetach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:13:34 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/25 16:29:50 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdetach(t_list **lst, t_list	*node)
{
	if (!*lst || !node)
		return (0);
	if (node->prev)
		(node->prev)->next = node->next;
	else
		*lst = node->next;
	if (node->next)
		(node->next)->prev = node->prev;
	node->next = 0;
	node->prev = 0;
	return (node);
}
