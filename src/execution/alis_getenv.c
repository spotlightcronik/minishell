/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alis_getenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:38:50 by auloth            #+#    #+#             */
/*   Updated: 2025/03/04 15:47:03 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

extern int	g_global;

char	*get_serch(char *str)
{
	int		count;
	char	*temp;

	count = 1;
	while (str[count] != 0 && str[count] != ' ' && str[count] != 39
		&& str[count] != 34)
		count++;
	temp = calloc(count, sizeof(char));
	if (!temp)
		return (NULL);
	count = 1;
	while (str[count] != 0 && str[count] != ' ' && str[count] != 39
		&& str[count] != 34)
	{
		temp[count - 1] = str[count];
		count++;
	}
	return (temp);
}

char	*expand_closer(char *new, char *str, char *add, int count)
{
	int	c;
	int	c2;

	c = -1;
	c2 = 0;
	while (++c < count)
		new[c] = str[c];
	c2 = c;
	while (str[c2] && str[c2] != ' ' && str[c2] != 39 && str[c2] != 34)
	{
		if(str[c2] == '?' && str[c2 - 1] == '$')
		{
			c2++;
			break;
		}
		c2++;
	}
	ft_strlcpy(&new[c], add, ft_strlen(add) + 1);
	c += ft_strlen(add);
	while (str[c2])
		new[c++] = str[c2++];
	return (free(str), new);
}

char	*expand(char *str, char *add, int count)
{
	int		c;
	int		size;
	char	*new;

	c = count;
	size = count - 1;
	while (str[c] && str[c] != ' ' && str[c] != 39 && str[c] != 34)
	{
		if(str[c] == '?' && str[c - 1] == '$')
		{
			c++;
			break;
		}
		c++;
	}
	while (str[c] != 0)
	{
		c++;
		size++;
	}
	if (size == -1)
		size = 0;
	new = ft_calloc(size + ft_strlen(add) + 2, sizeof(char));
	if (!new)
		return (NULL);
	return (expand_closer(new, str, add, count));
}

char	*add_param(char *str, int count)
{
	char	*result;
	char	*temp;

	result = get_serch(&str[count]);
	if (!result)
		return (NULL);
	if (*result == 0)
		return (free(result), str);
	if (result[0] == '?')
		return (free(result), expand(str, ft_itoa(g_global), count));
	temp = getenv(result);
	if (temp == NULL)
		return (free(result), str);
	free(result);
	return (expand(str, temp, count));
}

char	*check_env(char *str)
{
	int	count;

	count = 0;
	str = ft_strdup(str);
	while (str[count] != 0)
	{
		if (str[count] == '$')
			str = add_param(str, count);
		if (str == NULL)
			return (NULL);
		count++;
	}
	return (str);
}
