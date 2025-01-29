/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:29:43 by auloth            #+#    #+#             */
/*   Updated: 2025/01/28 16:10:19 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

int main(void)
{
	char *input;

	while (1)
	{
		input = readline("prompt > ");
		if(!input)
			perror("read line"));
		printf("%s\n", input);
	}
	return(0);

}
