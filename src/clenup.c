/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clenup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:38:50 by auloth            #+#    #+#             */
/*   Updated: 2025/03/04 15:50:24 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

static void	del_tokens(void *content)
{
	t_token		*del;
	int			count;

	del = content;
	count = 0;
	while (del[count].type)
	{
		free(del[count].type);
		free(del[count].content);
		count++;
	}
	free(del);
}

void	del_w_commands(void *content)
{
	t_command	*del;
	int			count;

	if (!content)
		return ;
	del = (t_command *)content;
	if (del->name)
		free(del->name);
	if (del->redir)
		del_tokens(del->redir);
	if (del->args)
	{
		count = 0;
		while (del->args && del->args[count] != NULL)
			free(del->args[count++]);
		free(del->args);
	}
	free(content);
	return ;
}

int	clenup(t_info *data)
{
	int	count;

	count = 0;
	while (count < data->token_list_size)
	{
		free(data->token_list[count].content);
		free(data->token_list[count].type);
		count++;
	}
	free(data->token_list);
	free(data->str);
	data->token_list_size = 0;
	return (1);
}

int	full_clenup(t_info *data)
{
	clenup(data);
	ft_lstclear(&data->env_param, free);
	return (1);
}

int	clenup_parser(t_info *data)
{
	ft_lstclear(&data->action_list, del_w_commands);
	return (1);
}
