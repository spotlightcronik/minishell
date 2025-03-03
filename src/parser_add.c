/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:09:05 by auloth            #+#    #+#             */
/*   Updated: 2025/03/03 15:04:29 by auloth           ###   ########.fr       */
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

int	add_to_list(t_token new, t_command *add)
{
	int		count;
	t_token	*temp;

	count = 0;
	while (add != NULL && add->redir[count].type != NULL)
		count++;
	temp = malloc((count + 1) * sizeof(t_token));
	if (!temp)
		return (1);
	count = 0;
	while (add != NULL && add->redir[count].type != NULL)
	{
		temp[count] = add->redir[count];
		count++;
	}
	temp[count] = new;
	temp[count + 1].type = NULL;
	free(add->redir);
	add->redir = temp;
	return (0);
}

int	add_redir(t_info *data, char *name)
{
	t_list		*temp;
	t_command	*add;
	t_token		new;

	temp = ft_lstlast(data->action_list);
	add = (t_command *)temp->content;
	if ((data->count + 1 >= data->token_list_size) || ft_strcmp(data->token_list[data->count + 1].type, "word") != 0)
		return (printf("Sintax error no word after redirection \n"), 1);
	data->count++;
	new.content = ft_strdup(data->token_list[data->count].content);
	if (!new.content)
		return (printf("Failed to allocate memory"), 1);
	new.type = ft_strdup(name);
	if (!new.type)
		return (printf("Failed to allocate memory"), 1);
	if (add_to_list(new, add) != 0)
		return (1);
	data->count++;
	return (0);
}
/*
int	add_redir(t_info *data, char *name)
{
	t_list		*temp;
	t_command	*add;
	t_token		new;

	temp = ft_lstlast(data->action_list);
	add = (t_command *)temp->content;
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
} */
