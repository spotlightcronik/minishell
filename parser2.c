/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:26:41 by auloth            #+#    #+#             */
/*   Updated: 2025/02/04 13:58:30 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

int dollar_sign(t_info *data)
{
	if (data->str[data->count] != '$')
		return(0);
	if (ft_getenv(data, data->count + 1, 0) != 0)
		return(1);
	return(0);
}

int word_len(t_info *data)
{
	int count;
	int pos;

	count = 0;
	pos = data->count;
	while(is_partofword(data->str[pos]))
	{
		if(data->str[pos] != 34 && data->str[pos] != 39)
			count++;
		pos++;
	}
	return(count);
}

int is_partofword(char c)
{
	if(c == '<' || c == '>' || c == 0)
		return(0);
	if(c == 34 || c == 39)
		return(1);
	if(c == ' ' ||  c == '$' || c == '|')
		return(0);
	return(1);
}


