/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:03:28 by auloth            #+#    #+#             */
/*   Updated: 2025/02/25 11:53:21 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

char	**ft_realoc(char **temp)
{
	int		count;
	char	**new;

	count = 0;
	if (temp != NULL)
		while (temp[count] != NULL)
			count++;
	new = ft_calloc((count + 2), sizeof(char *));
	if (!new)
		return (NULL);
	if (temp == NULL)
		return (new);
	ft_memcpy(new, temp, count * sizeof(char *));
	free(temp);
	new[count] = NULL;
	new[count + 1] = NULL;
	return (new);
}
