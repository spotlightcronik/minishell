/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttoar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:31:26 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/04 16:04:01 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_lsttoarr(t_list *lst)
{
	void	**value;
	int		index;

	if (!lst)
		return (0);
	value = ft_calloc(ft_lstsize(lst) + 1, sizeof(void *));
	if (!value)
		return (0);
	index = 0;
	while (lst)
	{
		value[index] = lst->content;
		index++;
		lst = lst->next;
	}
	return (value);
}
