/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:09:05 by auloth            #+#    #+#             */
/*   Updated: 2025/02/25 11:56:31 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

int	add_word(t_info *data, char *word)
{
	t_list		*temp;
	t_command	*add;
	int			count;

	count = 0;
	temp = ft_lstlast(data->action_list);
	add = (t_command *)temp->content;
	if (add->name != NULL)
	{
		add->args = ft_realoc(add->args);
		if (add->args == NULL)
			return (perror("Failed to realocate args"), 1);
		while (add->args[count] != NULL)
			count++;
		add->args[count] = ft_strdup(word);
	}
	else
	{
		add->name = ft_strdup(word);
		if (!add->name)
			return (perror("Failed to copy name"), 1);
	}
	return (data->count++, 0);
}

int	add_heredoc(t_info *data)
{
	t_list		*temp;
	t_command	*add;

	temp = ft_lstlast(data->action_list);
	add = (t_command *)temp->content;
	if (add->heredoc != NULL)
		return (perror("Failed to allocate heredoc"), 1);
	if (add->args != NULL && ft_strcmp(data->token_list[data->count + 1].type,
			"word") != 0)
		return (perror("Sintax error not word after heredoc"), 1);
	data->count++;
	add->heredoc = ft_strdup(data->token_list[data->count].content);
	if (!add->heredoc)
		return (perror("Failed to allocate heredoc"), 1);
	data->count++;
	return (0);
}

int	add_redir(t_info *data, int r)
{
	t_list		*temp;
	t_command	*add;

	temp = ft_lstlast(data->action_list);
	add = (t_command *)temp->content;
	if (add->heredoc != NULL)
		return (perror("Failed to find content"), 1);
	if (add->args != NULL && ft_strcmp(data->token_list[data->count + 1].type,
			"word") != 0)
		return (1);
	data->count++;
	if (r == 1)
		add->append = 1;
	add->output = ft_strdup(data->token_list[data->count].content);
	if (!add->heredoc)
		return (1);
	data->count++;
	return (0);
}

int	add_input(t_info *data)
{
	t_list		*temp;
	t_command	*add;

	temp = ft_lstlast(data->action_list);
	add = (t_command *)temp->content;
	if (add->heredoc != NULL)
		return (1);
	if (add->args != NULL && ft_strcmp(data->token_list[data->count + 1].type,
			"word") != 0)
		return (1);
	data->count++;
	add->infile = ft_strdup(data->token_list[data->count].content);
	if (!add->infile)
		return (1);
	data->count++;
	return (0);
}
