/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:36:01 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/25 10:35:07 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = 0;
	while (lst)
	{
		new_content = (*f)(lst->content);
		if (!new_content)
		{
			ft_lstclear(&new_list, (*del));
			return (0);
		}
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			free(new_content);
			ft_lstclear(&new_list, (*del));
			return (0);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
