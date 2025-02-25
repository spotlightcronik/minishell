/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:56:41 by auloth            #+#    #+#             */
/*   Updated: 2025/02/25 11:54:43 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

int	add_token(t_info *data, t_token tk)
{
	t_token	*temp;
	int		count;

	count = 0;
	temp = malloc((data->token_list_size + 1) * sizeof(t_token));
	if (!temp)
		return (1);
	data->token_list_size++;
	while (count < data->token_list_size - 1)
	{
		temp[count] = data->token_list[count];
		count++;
	}
	temp[count] = tk;
	if (data->token_list != NULL)
		free(data->token_list);
	data->token_list = temp;
	return (0);
}

int	create_token(t_info *data, char *simbol, char *name)
{
	t_token	add;

	add.content = ft_strdup(simbol);
	if (!add.content)
		return (1);
	add.type = ft_strdup(name);
	if (!add.type)
		return (1);
	if (add_token(data, add) != 0)
		return (1);
	return (0);
}
