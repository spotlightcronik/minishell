/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnextsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:02:42 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/30 11:25:00 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstnextsize(t_list *lst)
{
	int	value;

	if (!lst)
		return (0);
	value = 0;
	while (lst->next)
	{
		value++;
		lst = lst->next;
	}
	return (value);
}
