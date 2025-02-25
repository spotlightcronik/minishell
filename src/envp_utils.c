/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:18:45 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/25 15:00:28 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	handler_envp(void *s1, void *s2)
{
	return (ft_strncmp(s1, s2, ft_strlen(s2)));
}

t_list	*ft_envp_node(t_list *envp, char *env_name)
{
	t_list	*node;
	char	*placeholder;

	placeholder = ft_strjoin(env_name, "=");
	if (!placeholder)
		return (NULL);
	node = ft_lstchr(envp, placeholder, handler_envp);
	free(placeholder);
	return (node);
}

char	*ft_getenv(t_list *envp, char *env_name)
{
	t_list	*node;

	node = ft_envp_node(envp, env_name);
	if (!node)
		return (NULL);
	return (node->content);
}

int	ft_setenv(t_list *envp, char *env_name, char *value)
{
	char	*placeholder;
	t_list	*node;

	if (value)
		placeholder = ft_freejoin(ft_strjoin(env_name, "="), value);
	else
		placeholder = ft_strdup(env_name);
	if (!placeholder)
		return (-1);
	node = ft_envp_node(envp, env_name);
	if (!node)
		ft_lstadd_back(&envp, ft_lstnew(placeholder));
	else
	{
		free(node->content);
		node->content = placeholder;
	}
	return (0);
}
