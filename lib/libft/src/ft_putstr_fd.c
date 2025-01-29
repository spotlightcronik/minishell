/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:39:52 by jeperez-          #+#    #+#             */
/*   Updated: 2024/12/13 11:34:41 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putstr_fd(char *s, int fd)
{
	int		index;
	ssize_t	length;

	if (!s)
		return (ft_putstr_fd("(null)", fd));
	index = 0;
	length = 0;
	while (s[index])
	{
		length += ft_putchar_fd(s[index], fd);
		index++;
	}
	return (length);
}
