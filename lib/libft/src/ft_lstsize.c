/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:11:40 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/30 11:02:22 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	value;

	if (!lst)
		return (0);
	while (lst->prev)
	{
		lst = lst->prev;
	}
	value = 1;
	while (lst->next)
	{
		value++;
		lst = lst->next;
	}
	return (value);
}
