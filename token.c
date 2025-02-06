/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:52:09 by auloth            #+#    #+#             */
/*   Updated: 2025/02/06 14:54:20 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

int	dollar_sign(t_info *data)
{
	if (data->str[data->count] != '$')
		return (0);
	if (ft_getenv(data, data->count + 1, 0) != 0)
		return (1);
	return (0);
}

int	quotes(t_info *data, char quotes)
{
	int		count;
	char	*temp;

	if (data->str[data->count] != quotes)
		return (0);
	data->count++;
	count = data->count;
	while (data->str[count] != quotes)
	{
		if (quotes != 39 && data->str[count] == '$' && ft_getenv(data, count
				+ 1, 1) != 0)
			return (0);
		if (data->str[count] == 0)
			return (printf("Error: unclosed quotes\n"), 1);
		count++;
	}
	count++;
	temp = malloc((count - data->count + 1) * sizeof(char));
	if (!temp)
		return (1);
	ft_strlcpy(temp, &data->str[data->count], count - data->count);
	data->count = count;
	if (create_token(data, temp, "txt") != 0)
		return (1);
	return (free(temp), 0);
}

int	check_for_operator(t_info *data)
{
	if (data->str[data->count] == '|')
		return (data->count++, create_token(data, "|", "pipe"));
	if (data->str[data->count] == '<' && data->str[data->count + 1] == '<')
		return (data->count += 2, create_token(data, "<<", "heredoc"));
	if (data->str[data->count] == '>' && data->str[data->count + 1] == '>')
		return (data->count += 2, create_token(data, ">>", "apend redirec"));
	if (data->str[data->count] == '>')
		return (data->count++, create_token(data, ">", "output redirection"));
	if (data->str[data->count] == '<')
		return (data->count++, create_token(data, "<", "input redirection"));
	return (0);
}

int	token_word(t_info *data)
{
	int		count;
	char	*new;

	if (!is_partofword(data->str[data->count]) || data->str[data->count] == 34
		|| data->str[data->count] == 39)
		return (0);
	count = word_len(data);
	if (count == 0)
		return (1);
	if (data->q.passed == 1)
		return (printf("Error: unclosed quotes\n"), 1);
	new = malloc((count + 1) * sizeof(char));
	if (!new)
		return (1);
	copy_word(data, new, count + 1);
	return (create_token(data, new, "word"), free(new), 0);
}

int	tokenize(t_info *data)
{
	data->count = 0;
	while (data->str[data->count] != 0)
	{
/* 		if (dollar_sign(data) != 0)
			return (1); */
		if (quotes(data, 34) != 0)
			return (1);
		if (quotes(data, 39) != 0)
			return (1);
		if (check_for_operator(data) != 0)
			return (1);
		if (token_word(data) != 0)
			return (1);
		if (data->str[data->count] == ' ')
			data->count++;
	}
	return (0);
}
