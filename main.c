/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:29:43 by auloth            #+#    #+#             */
/*   Updated: 2025/02/05 17:43:04 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

int init_data(t_info *data, int ac, char **av, char **ip)
{
	data->token_list_size = 0;
	data->token_list = NULL;
	data->count = 0;
	data->env_param = NULL;
	data->ip = ip;
	data->q.passed = 0;
	data->dollar_signs = 0;
	if (dtll(&data->env_param, ip) != 0)
		return(1);
	(void)av;
	(void)ac;
	return(0);
}
void print_result(t_info *data)
{
	int count;

	count = 0;
	while (count < data->token_list_size)
		{
			printf("\n%s\n", data->token_list[count].type);
			printf("%s\n", data->token_list[count].content);
			free(data->token_list[count].content);
			free(data->token_list[count].type);
			count++;
		}
		free(data->str);
		data->token_list_size = 0;
}

int main(int ac, char**av, char **ip)
{
	t_info data;

	if(init_data(&data, ac, av, ip) != 0)
		return(clenup(&data));
	while (1)
	{
		data.str = readline("prompt > ");
		if(!data.str)
			perror("read line");
		if (tokenize(&data) != 0)
		{
			clenup(&data);
			init_data(&data, ac, av, ip);
		}
		else
			print_result(&data);
	}
	return(0);

}
