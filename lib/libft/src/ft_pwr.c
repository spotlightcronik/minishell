/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:31:37 by jeperez-          #+#    #+#             */
/*   Updated: 2024/12/13 11:33:50 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pwr(int base, int power)
{
	int	total;

	total = 1;
	while (power)
	{
		total *= base;
		if (power > 0)
			power--;
		else
			power++;
	}
	return (total);
}
