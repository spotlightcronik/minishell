/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_linked_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:40:03 by auloth            #+#    #+#             */
/*   Updated: 2025/02/25 14:23:09 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

extern int	g_global;

int	insert_envpar(char **dest, char *add, int place)
{
	char	*new;
	int		count;

	count = 0;
	new = malloc((ft_strlen((*dest)) + ft_strlen(add) + 1) * sizeof(char));
	if (!new)
		return (0);
	while ((*dest)[count] != '$' || count < place)
	{
		new[count] = (*dest)[count];
		count++;
	}
	new[count] = 0;
	ft_strlcat(new, add, ft_strlen((*dest)) + ft_strlen(add));
	count++;
	while (ft_isalpha((*dest)[count]) || ft_isdigit((*dest)[count])
		|| (*dest)[count] == '_')
		count++;
	ft_strlcat(new, &(*dest)[count], ft_strlen((*dest)) + ft_strlen(add) + 1);
	free(*dest);
	*dest = new;
	return (0);
}

void	no_env_copy_morelines(t_info *data, int count, int count2, char *temp)
{
	while (data->str[count] != 0)
	{
		temp[count2] = data->str[count];
		count++;
		count2++;
	}
}

int	insert_global(char **dest, char *add, int place)
{
	char	*new;
	int		count;

	count = 0;
	if (ft_strlen(add) == 1)
		new = malloc((ft_strlen((*dest)) + ft_strlen(add)) * sizeof(char));
	else
		new = malloc((ft_strlen((*dest)) + ft_strlen(add) + 1) * sizeof(char));
	if (!new)
		return (0);
	while ((*dest)[count] != '$' || count < place)
	{
		new[count] = (*dest)[count];
		count++;
	}
	new[count] = 0;
	ft_strlcat(new, add, ft_strlen((*dest)) + ft_strlen(add));
	count++;
	count++;
	ft_strlcat(new, &(*dest)[count], ft_strlen((*dest)) + ft_strlen(add) + 1);
	free(*dest);
	*dest = new;
	return (0);
}

void	getenv_morelines(char *arr, t_list *temp, int *count)
{
	free(arr);
	arr = (char *)temp->content;
	while (arr[*count] != '=')
		(*count)++;
	(*count)++;
}

int	ft_getenv_parse(t_info *data, int co, int insert)
{
	t_list	*temp;
	char	*arr;
	int		count;

	count = co;
	if (data->str[count] == '?')
		return (insert_global(&data->str, ft_itoa(g_global), co - 1));
	while (ft_isalpha(data->str[count]) || ft_isdigit(data->str[count])
		|| data->str[count] == '_')
		count++;
	arr = malloc(((count - co) + 1) * sizeof(char));
	if (!arr)
		return (1);
	ft_strlcpy(arr, &data->str[co], count - co + 1);
	if (ft_strcmp(arr, "$?") == 0)
		return (free(arr), insert_envpar(&data->str, ft_itoa(g_global), co
				- 1));
	count = 0;
	temp = ft_lstchr(data->env_param, arr, handler);
	if (!temp)
		return (no_env(data, co));
	getenv_morelines(arr, temp, &count);
	if (insert == 1)
		return (insert_envpar(&data->str, &arr[count], co - 1));
	return (data->count++, create_token(data, &arr[count], "env param"));
}
