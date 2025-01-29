/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:44:25 by jeperez-          #+#    #+#             */
/*   Updated: 2024/12/13 11:34:44 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbr_fd(int n, int fd)
{
	ssize_t	length;

	if (n == -2147483648)
	{
		length = ft_putstr_fd("-2147483648", fd);
		return (length);
	}
	length = 0;
	if (n < 0)
	{
		length += ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
		length += ft_putnbr_fd(n / 10, fd);
	length += ft_putchar_fd(n % 10 + '0', fd);
	return (length);
}
