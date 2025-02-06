/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_clenup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:38:50 by auloth            #+#    #+#             */
/*   Updated: 2025/02/05 12:00:23 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

void del(void *nothing)
{
	(void)nothing;
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
	ft_lstclear(&data->env_param, del);
	free(data->token_list);
	free(data->str);
	data->token_list_size = 0;
	return (1);
}
