/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:30:11 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/25 15:19:17 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfirst(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->prev)
	{
		lst = lst->prev;
	}
	return (lst);
}
