/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:56:41 by auloth            #+#    #+#             */
/*   Updated: 2025/03/05 11:41:03 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

int	dtll(t_list **list, char **arr)
{
	int		count;
	t_list	*temp;

	count = 0;
	while (arr[count] != NULL)
	{
		temp = ft_lstnew(ft_strdup(arr[count]));
		if (!temp)
			return (1);
		ft_lstadd_back(list, temp);
		count++;
	}
	return (0);
}

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

int	no_env_copy(t_info *data, int co, char *temp)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 0;
	while (count < co - 1)
	{
		temp[count] = data->str[count];
		count++;
	}
	count2 = count;
	count++;
	while (ft_isalpha(data->str[count]) || ft_isdigit(data->str[count])
		|| data->str[count] == '_')
		count++;
	no_env_copy_morelines(data, count, count2, temp);
	if ((temp[co - 1] == 34) || temp[co - 1] == 39)
		set_q(data, temp[co - 1]);
	return (free(data->str), data->str = temp, 0);
}

int	no_env(t_info *data, int co)
{
	int		count;
	int		size;
	char	*temp;

	count = 0;
	size = 0;
	while (count < co)
		count++;
	size = count;
	while (ft_isalpha(data->str[count]) || ft_isdigit(data->str[count])
		|| data->str[count] == '_')
		count++;
	while (data->str[count] != 0)
	{
		count++;
		size++;
	}
	temp = malloc(size + 1);
	if (!temp)
		return (1);
	return (no_env_copy(data, co, temp));
}
