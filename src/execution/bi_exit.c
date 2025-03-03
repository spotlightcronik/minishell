/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:15:02 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/03 15:10:22 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static t_bool	ft_isnumber(char *str)
{
	int	index;

	index = 0;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (ft_isdigit(str[index]))
		index++;
	if (str[index])
		return (false);
	return (true);
}

void	execute_exit(t_execution *exec)
{
	int			argc;
	int			exit_code;
	t_command	*cmd;

	cmd = exec->current->content;
	argc = 0;
	if (cmd->args)
		while (cmd->args[argc])
			argc++;
	g_global = 1;
	if (argc > 1 || (argc == 1 && !ft_isnumber(cmd->args[0])))
		ft_printf("Usage: exit [number]\n");
	else
	{
		exit_code = g_global;
		if (argc)
			exit_code = ft_atoi(cmd->args[0]);
		if (exec->cmds)
			ft_lstclear(&exec->cmds, free_cmd);
		if (exec->envp)
			ft_lstclear(&exec->envp, free);
		clear_history();
		exit(exit_code);
	}
}
