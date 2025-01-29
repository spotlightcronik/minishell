/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:03:16 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/28 14:01:57 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INT_H
# define FT_PRINTF_INT_H

# include "libft.h"

ssize_t		ft_print_variadic(const char *str, va_list lst, int fd);
ssize_t		ft_printptr(void *ptr, int fd);
ssize_t		ft_printnbr(int nbr, int fd);
ssize_t		ft_printunbr(unsigned int nbr, int fd);
ssize_t		ft_printhex(int hex, int fd, int upp);
char		*ft_uitoa(unsigned int n);
char		*ft_ptrtoa(void *ptr);
char		*ft_hextoa(unsigned int hex, int upp);

#endif 
