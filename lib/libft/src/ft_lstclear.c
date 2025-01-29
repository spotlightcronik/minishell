/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:24:55 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/25 11:23:25 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (*lst == 0)
		return ;
	while ((*lst)->next)
	{
		*lst = (*lst)->next;
		ft_lstdelone((*lst)->prev, (*del));
	}
	ft_lstdelone(*lst, (*del));
	*lst = 0;
}
