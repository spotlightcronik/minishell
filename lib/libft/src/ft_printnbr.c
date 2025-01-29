/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:44:20 by jeperez-          #+#    #+#             */
/*   Updated: 2024/12/13 11:34:48 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

ssize_t	ft_printnbr(int nbr, int fd)
{
	char		*str;
	ssize_t		length;

	str = ft_itoa(nbr);
	if (!str)
		return (-1);
	length = ft_putstr_fd(str, fd);
	free(str);
	return (length);
}

ssize_t	ft_printunbr(unsigned int nbr, int fd)
{
	char	*str;
	int		length;

	str = ft_uitoa(nbr);
	if (!str)
		return (-1);
	length = ft_putstr_fd(str, fd);
	free(str);
	return (length);
}
