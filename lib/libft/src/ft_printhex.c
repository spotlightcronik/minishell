/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:55:39 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/28 13:38:14 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

ssize_t	ft_printhex(int hex, int upp, int fd)
{
	char	*str;
	ssize_t	length;

	str = ft_hextoa(hex, upp);
	if (!str)
		return (-1);
	length = ft_putstr_fd(str, fd);
	free(str);
	return (length);
}
