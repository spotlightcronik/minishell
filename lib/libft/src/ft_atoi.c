/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:23:28 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/21 16:43:10 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nbr(const char *nptr)
{
	int	index;
	int	nbr;

	nbr = 0;
	index = 0;
	while (ft_isdigit(nptr[index]))
	{
		nbr *= 10;
		nbr += nptr[index] - 48;
		index++;
	}
	return (nbr);
}

int	ft_atoi(const char *nptr)
{
	int	index;
	int	sign;

	index = 0;
	while (ft_isspace(nptr[index]))
		index++;
	sign = 1;
	if (nptr[index] == '-')
	{
		sign = -1;
		index++;
	}
	else if (nptr[index] == '+')
		index++;
	return (get_nbr(nptr + index) * sign);
}
