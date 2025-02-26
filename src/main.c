/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:29:43 by auloth            #+#    #+#             */
/*   Updated: 2025/02/26 11:42:27 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

int	g_global;

int	init_data(t_info *data, int ac, char **av, char **ip)
{
	using_history();
	init_signals();
	(void)av;
	(void)ac;
	data->token_list_size = 0;
	data->token_list = NULL;
	data->count = 0;
	data->ip = ip;
	data->q.passed = 0;
	data->dollar_signs = 0;
	data->action_list = NULL;
	if (data->initialize == 0)
	{
		g_global = 0;
		data->env_param = NULL;
		if (dtll(&data->env_param, ip) != 0)
			return (1);
		data->initialize = 1;
	}
	return (0);
}

int	main(int ac, char **av, char **ip)
{
	t_info	data;

	data.initialize = 0;
	while (1)
	{
		if (init_data(&data, ac, av, ip) != 0)
			return (clenup(&data));
		data.str = readline("prompt > ");
		if (!data.str)
			return (printf("Exit"), clenup(&data));
		add_history(data.str);
		if (tokenize(&data) != 0 || data.token_list_size == 0)
			clenup(&data);
		else
		{
			data.count = 0;
			if (parser(&data) == 0)
			{
				clenup(&data);
				execute_line(data.action_list, data.env_param);
			}
			clenup_parser(&data);
		}
	}
	return (0);
}
