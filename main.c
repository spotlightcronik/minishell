/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:29:43 by auloth            #+#    #+#             */
/*   Updated: 2025/02/24 16:11:51 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

int	init_data(t_info *data, int ac, char **av, char **ip)
{
	data->token_list_size = 0;
	data->token_list = NULL;
	data->count = 0;
	data->env_param = NULL;
	data->ip = ip;
	data->q.passed = 0;
	data->dollar_signs = 0;
	data->action_list = NULL;
	if (dtll(&data->env_param, ip) != 0)
		return (1);
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

	if (init_data(&data, ac, av, ip) != 0)
		return (clenup(&data));
	while (1)
	{
		data.str = readline("prompt > ");
		if (!data.str)
			perror("read line");
		if (tokenize(&data) != 0 || data.token_list_size == 0)
		{
			clenup(&data);
			init_data(&data, ac, av, ip);
		}
		else
		{
			data.count = 0;
			if (parser(&data) == 0)
				data.count = 0;
			print_result(&data);
			clenup_parser(&data);
			init_data(&data, ac, av, ip);
		}
	}
	return (0);
}
