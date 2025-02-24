/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clenup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:38:50 by auloth            #+#    #+#             */
/*   Updated: 2025/02/24 16:37:13 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

void del(void *arr)
{
	free(arr);
	return;
}

void del_w_commands(void *content)
{
	t_command *del;
	int count;

	if(!content)
		return;
	count = 0;
	del = (t_command *)content;
	if(del->heredoc)
		free(del->heredoc);
	if(del->infile)
		free(del->infile);
	if(del->name)
		free(del->name);
	if(del->output)
		free(del->output);
	while(del->args && del->args[count] != NULL)
	{
		free(del->args[count]);
		count++;
	}
	free(content);
	return;
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
	ft_lstclear(&data->env_param, free);
	free(data->token_list);
	free(data->str);
	data->token_list_size = 0;
	return (1);
}

int clenup_parser(t_info *data)
{
	clenup(data);
	ft_lstclear(&data->action_list, del_w_commands);
	return(1);
}
