/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_extra_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:26:41 by auloth            #+#    #+#             */
/*   Updated: 2025/02/25 14:20:26 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

void	set_q(t_info *data, char c)
{
	if (data->q.passed == 0)
		data->q.type = c;
	if (data->q.passed == 0)
		data->q.passed = 1;
	else if (data->q.type == c)
	{
		data->q.passed = 0;
		data->q.type = 0;
	}
}

int	word_len(t_info *data)
{
	int	count;
	int	pos;

	count = 0;
	pos = data->count;
	while (is_partofword(data->str[pos]) || data->q.passed == 1)
	{
		if ((data->str[pos] == 34) || data->str[pos] == 39)
			set_q(data, data->str[pos]);
		if ((data->str[pos] != 34 && data->str[pos] != 39)
			|| ((data->str[pos] == 34 || data->str[pos] == 39)
				&& data->str[pos] != data->q.type && data->q.passed != 0))
			count++;
		if (data->str[pos] == '$' && data->q.type != 39 && ft_getenv_parse(data,
				pos + 1, 1) != 0 && pos++ > -1)
			return (0);
		pos++;
	}
	return (count);
}

int	is_partofword(char c)
{
	if (c == '<' || c == '>' || c == 0)
		return (0);
	if (c == 34 || c == 39)
		return (1);
	if (c == ' ' || c == '|')
		return (0);
	return (2);
}

int	handler(void *str, void *reference)
{
	return (ft_strncmp(str, reference, ft_strlen(reference)));
}

void	copy_word(t_info *data, char *new, int count)
{
	int	pos;

	data->q.type = 0;
	pos = 0;
	while (pos < count && data->str[data->count] != 0 && (data->q.passed != 0
			|| is_partofword(data->str[data->count])))
	{
		if ((data->str[data->count] == 34) || data->str[data->count] == 39)
			set_q(data, data->str[data->count]);
		if ((data->str[data->count] != 34 && data->str[data->count] != 39)
			|| ((data->str[data->count] == 34 || data->str[data->count] == 39)
				&& data->str[data->count] != data->q.type
				&& data->q.passed != 0))
		{
			new[pos] = data->str[data->count];
			pos++;
		}
		data->count++;
	}
	new[pos] = 0;
}
