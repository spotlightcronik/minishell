/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:16:26 by auloth            #+#    #+#             */
/*   Updated: 2025/03/03 14:20:11 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

int	add_comand(t_info *data)
{
	t_command	*command;
	t_list		*new;

	command = malloc(sizeof(t_command));
	if (!command)
		return (1);
	new = ft_lstnew(command);
	if (!new)
		return (free(command), 1);
	command->name = NULL;
	command->args = NULL;
	command->redir = malloc(sizeof(t_token));
	if(!command->redir)
		return(1);
	command->redir->type = NULL;
	ft_lstadd_back(&data->action_list, new);
	return (0);
}

int	redir(t_info *data, char *word)
{
	if (ft_strcmp(word, "<<") == 0)
		return (add_redir(data, "heredoc"));
	if (ft_strcmp(word, ">>") == 0)
		return (add_redir(data, "append"));
	if (ft_strcmp(word, "<") == 0)
		return (add_redir(data, "infile"));
	if (ft_strcmp(word, ">") == 0)
		return (add_redir(data, "outfile"));
	return (0);
}

int	parser(t_info *data)
{
	if (ft_strcmp(data->token_list[data->count].content, "|") == 0)
		return (1);
	else
		add_comand(data);
	while (data->count < data->token_list_size)
	{
		if (ft_strcmp(data->token_list[data->count].type, "word") == 0
			&& add_word(data, data->token_list[data->count].content) != 0)
			return (1);
		if (data->count >= data->token_list_size)
			return (0);
		if (redir(data, data->token_list[data->count].content) != 0)
			return (1);
		if (data->count >= data->token_list_size)
			return (0);
		if (ft_strcmp(data->token_list[data->count].content, "|") == 0)
		{
			if (data->count + 1 < data->token_list_size
				&& ft_strcmp(data->token_list[data->count + 1].content,
					"|") != 0)
				return (data->count++, parser(data));
			return (1);
		}
	}
	return (0);
}
