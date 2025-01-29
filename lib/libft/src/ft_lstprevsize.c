/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprevsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:16:55 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/30 11:25:09 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstprevsize(t_list *lst)
{
	int	value;

	if (!lst)
		return (0);
	value = 0;
	while (lst->prev)
	{
		value++;
		lst = lst->prev;
	}
	return (value);
}
