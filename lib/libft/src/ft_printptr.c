/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:11:44 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/28 13:34:27 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

ssize_t	ft_printptr(void *ptr, int fd)
{
	char	*str;
	ssize_t	length;

	if (!ptr)
		return (ft_putstr_fd("(nil)", fd));
	str = ft_ptrtoa(ptr);
	if (!str)
		return (-1);
	length = ft_putstr_fd(str, fd);
	free (str);
	return (length);
}
