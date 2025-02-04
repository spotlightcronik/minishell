/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:29:43 by auloth            #+#    #+#             */
/*   Updated: 2025/02/04 13:58:38 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

int init_data(t_info *data, int ac, char **av, char **ip)
{
	data->token_list_size = 0;
	data->token_list = NULL;
	data->count = 0;
	data->env_param = NULL;
	if (dtll(&data->env_param, ip) != 0)
		return(1);
	(void)av;
	(void)ac;
	return(0);
}

int main(int ac, char**av, char **ip)
{
	t_info data;
	int count;

	count = 0;
	if(init_data(&data, ac, av, ip) != 0)
		return(clenup1());
	while (1)
	{
		data.str = readline("prompt > ");
		if(!data.str)
			perror("read line");
		tokenize(&data);
		while (count < data.token_list_size)
		{
			printf("\n%s\n", data.token_list[count].type);
			printf("%s\n", data.token_list[count].content);
			free(data.token_list[count].content);
			free(data.token_list[count].type);
			count++;
		}
		free(data.str);
	}
	return(0);

}
