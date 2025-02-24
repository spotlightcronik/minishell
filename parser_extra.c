/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:03:28 by auloth            #+#    #+#             */
/*   Updated: 2025/02/20 14:05:12 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

char **ft_realoc(char **temp)
{
	int count;
	char **new;

	count = 0;
	while(temp != NULL && temp[count] != NULL)
		count++;
	new = malloc((count + 2) * sizeof(char *));
	if(!new)
		return(NULL);
	if(temp == NULL)
		return(new[count] = NULL, new[count + 1] = NULL, new);
	count = 0;
	while (temp[count] != NULL)
	{
		new[count] = temp[count];
		count++;
	}
	free(temp);
	new[count] = NULL;
	count++;
	new[count] = NULL;
	return(new);
}
