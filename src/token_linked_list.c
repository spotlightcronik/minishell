/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_linked_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:40:03 by auloth            #+#    #+#             */
/*   Updated: 2025/02/25 12:51:01 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

extern int	global;

int	stll(t_list **list, t_command *arr, int size)
{
	int		count;
	t_list	*temp;

	count = 0;
	while (count < size)
	{
		temp = ft_lstnew((void *)&arr[count]);
		if (!temp)
			return (1);
		ft_lstadd_back(list, temp);
		count++;
	}
	return (0);
}

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

int	handler(void *str, void *reference)
{
	return (ft_strncmp(str, reference, ft_strlen(reference)));
}

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
	if (data->str[count] == ' ')
		count++;
	while (data->str[count] != 0)
	{
		temp[count2] = data->str[count];
		count++;
		count2++;
	}
	if ((temp[co - 1] == 34) || temp[co - 1] == 39)
		set_q(data, temp[co - 1]);
	return (temp[count2] = 0, free(data->str), data->str = temp, 0);
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
	if (data->str[count] == ' ')
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

int	ft_getenv_parse(t_info *data, int co, int insert)
{
	t_list	*temp;
	char	*arr;
	int		count;

	count = co;
	if (data->str[count] == '?')
		return (insert_global(&data->str, ft_itoa(global), co - 1));
	while (ft_isalpha(data->str[count]) || ft_isdigit(data->str[count])
		|| data->str[count] == '_')
		count++;
	arr = malloc(((count - co) + 1) * sizeof(char));
	if (!arr)
		return (1);
	ft_strlcpy(arr, &data->str[co], count - co + 1);
	if (ft_strcmp(arr, "$?") == 0)
		return (free(arr), insert_envpar(&data->str, ft_itoa(global), co - 1));
	count = 0;
	temp = ft_lstchr(data->env_param, arr, handler);
	if (!temp)
		return (no_env(data, co));
	free(arr);
	arr = (char *)temp->content;
	while (arr[count] != '=')
		count++;
	count++;
	if (insert == 1)
		return (insert_envpar(&data->str, &arr[count], co - 1));
	return (data->count++, create_token(data, &arr[count], "env param"));
}
