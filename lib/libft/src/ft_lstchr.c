/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:22:32 by jeperez-          #+#    #+#             */
/*   Updated: 2024/12/13 12:54:59 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstchr(t_list *lst, void *data_ref, int (*cmp)(void *, void *))
{
	t_list	*node;

	if (!lst)
		return (NULL);
	node = lst;
	while (node)
	{
		if (!cmp(node->content, data_ref))
			return (node);
		node = node->next;
	}
	return (NULL);
}
