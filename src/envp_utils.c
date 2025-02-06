/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:18:45 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/06 15:33:03 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	handler(void *s1, void *s2)
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
	node = ft_lstchr(&envp, placeholder, handler);
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

	node = ft_envp_node(envp, env_name);
	if (!node)
		return (-1);
	placeholder = ft_freejoin(ft_strjoin(env_name, "="), value);
	if (!placeholder)
		return (-1);
	free(node->content);
	node->content = placeholder;
	return (0);
}
