/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:52:09 by auloth            #+#    #+#             */
/*   Updated: 2025/03/05 13:13:36 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

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

	if (!is_partofword(data->str[data->count]))
		return (0);
	count = word_len(data);
	if (data->q.passed == 1)
		return (printf("Error: unclosed quotes\n"), 1);
	new = malloc((count + 1) * sizeof(char));
	if (!new)
		return (1);
	copy_word(data, new, count + 1);
	if (ft_strlen(new) == 0)
		return (0);
	return (create_token(data, new, "word"), free(new), 0);
}

int	tokenize(t_info *data)
{
	if (data->str && data->str[0])
		add_history(data->str);
	data->count = 0;
	while (data->str[data->count] != 0)
	{
		if (check_for_operator(data) != 0)
			return (1);
		if (token_word(data) != 0)
			return (1);
		if (data->str[data->count] == ' ')
			data->count++;
	}
	return (0);
}
