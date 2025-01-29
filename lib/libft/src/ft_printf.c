/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:21:22 by jeperez-          #+#    #+#             */
/*   Updated: 2024/12/13 11:34:53 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

ssize_t	ft_printf(char const *str, ...)
{
	va_list	lst;
	ssize_t	length;

	va_start(lst, str);
	length = ft_print_variadic(str, lst, STDIN_FILENO);
	va_end(lst);
	return (length);
}
