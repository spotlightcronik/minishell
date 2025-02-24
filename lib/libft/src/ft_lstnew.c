/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:06:20 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/24 15:58:20 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*value;

	if (!content)
		return (NULL);
	value = ft_calloc(1, sizeof(t_list));
	if (!value)
		return (NULL);
	value->content = content;
	value->prev = 0;
	value->next = 0;
	return (value);
}
