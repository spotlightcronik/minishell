/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_variadic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:21:44 by jeperez-          #+#    #+#             */
/*   Updated: 2024/12/13 12:51:27 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

static ssize_t	print_argument(char c, va_list arg_list, int fd)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(arg_list, int), fd));
	if (c == 's')
		return (ft_putstr_fd(va_arg(arg_list, char *), fd));
	if (c == 'p')
		return (ft_printptr(va_arg(arg_list, void *), fd));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(arg_list, int), fd));
	if (c == 'u')
		return (ft_printunbr(va_arg(arg_list, unsigned int), fd));
	if (c == 'x')
		return (ft_printhex(va_arg(arg_list, int), 0, fd));
	if (c == 'X')
		return (ft_printhex(va_arg(arg_list, int), 1, fd));
	if (c == '%')
		return (ft_putchar_fd('%', fd));
	return (-1);
}

static ssize_t	print_format(const char *str, va_list arg_list, int fd)
{
	int		index;
	ssize_t	length;

	length = 0;
	index = -1;
	while (str[++index])
	{
		if (str[index] == '%')
			length += print_argument(str[++index], arg_list, fd);
		else
			length += ft_putchar_fd(str[index], fd);
	}
	return (length);
}

ssize_t	ft_print_variadic(const char *str, va_list arg_list, int fd)
{
	if (write(1, 0, 0) == -1)
		return (-1);
	return (print_format(str, arg_list, fd));
}
