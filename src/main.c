/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:29:43 by auloth            #+#    #+#             */
/*   Updated: 2025/03/05 13:13:29 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

int	g_global;

static void	print_banner(void)
{
	printf("-------------------------------------------------\n");
	printf("       *                                         \n");
	printf("     (  `                         )       (   (  \n");
	printf("    )\\))(   (         (       ( /(    (  )\\  )\\  \n");
	printf("   ((_)()\\  )\\   (    )\\  (   )\\())  ))\\((_)((_) \n");
	printf("   (_()((_)((_)  )\\ )((_) )\\ ((_)\\  /((_)_   _   \n");
	printf("   |  \\/  | (_) _(_/( (_)((_)| |(_)(_)) | | | |  \n");
	printf("   | |\\/| | | || ' \\))| |(_-<| ' \\ / -_)| | | |  \n");
	printf("   |_|  |_| |_||_||_| |_|/__/|_||_|\\___||_| |_|  \n");
	printf("        -[ jeperez- ]-        -[ auloth ]-        \n");
	printf("-------------------------------------------------\n");
}

static int	init_data(t_info *data, int ac, char **av, char **ip)
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
		print_banner();
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
			return (printf("Exit"), full_clenup(&data));
		if (tokenize(&data) != 0 || data.token_list_size == 0)
			clenup(&data);
		else
		{
			data.count = 0;
			if (parser(&data) == 0)
			{
				clenup(&data);
				execute_line(data.action_list, &data.env_param);
			}
			clenup_parser(&data);
		}
	}
	return (0);
}
