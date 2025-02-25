/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:29:43 by auloth            #+#    #+#             */
/*   Updated: 2025/02/24 19:53:41 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

int global = 0;

int	init_data(t_info *data, int ac, char **av, char **ip)
{
	data->token_list_size = 0;
	data->token_list = NULL;
	data->count = 0;
	data->ip = ip;
	data->q.passed = 0;
	data->dollar_signs = 0;
	data->action_list = NULL;
	if(data->initialize == 0)
	{
		data->env_param = NULL;
		if (dtll(&data->env_param, ip) != 0)
			return (1);
	}
	(void)av;
	(void)ac;
	return (0);
}
void	print_result(t_info *data)
{
	int			count2;
	t_list		*next;
	t_command	*temp;

	next = data->action_list;
	printf("\n");
	while (next != NULL)
	{
		temp = (t_command *)next->content;
		printf("Heredoc: %s\n", temp->heredoc);
		printf("Infile: %s\n", temp->infile);
		printf("Name: %s\n", temp->name);
		printf("Append: %i\n", temp->append);
		printf("Output: %s\n", temp->output);
		count2 = 0;
		while (temp->args != NULL && temp->args[count2] != NULL)
		{
			printf("Arg: %i %s\n", count2, temp->args[count2]);
			count2++;
		}
		next = next->next;
		printf("\n");
	}
}

int	main(int ac, char **av, char **ip)
{
	t_info	data;

	data.initialize = 0;
	using_history();
	while (1)
	{
		if (init_data(&data, ac, av, ip) != 0)
			return (clenup(&data));
		data.initialize = 1;
		data.str = readline("prompt > ");
		if (!data.str)
			perror("read line");
		if (tokenize(&data) != 0 || data.token_list_size == 0)
			clenup(&data);
		else
		{
			data.count = 0;
			if (parser(&data) == 0 )
			{
				add_history(data.str);
				clenup(&data);
				execute_line(data.action_list, data.env_param);
			}
			clenup_parser(&data);
		}
	}
	return (0);
}
