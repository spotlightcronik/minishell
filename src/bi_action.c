/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:15:02 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/25 16:02:50 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	execute_unset(t_execution *exec)
{
	t_command	*cmd;
	int			index;
	t_list		*node;

	index = 0;
	cmd = exec->current->content;
	if (cmd->args)
	{
		while (cmd->args[index])
		{
			node = ft_envp_node(exec->envp, cmd->args[index]);
			if (node)
				ft_lstdelone(ft_lstdetach(&exec->envp, node), free);
			index++;
		}
	}
}

static void	export_print(t_execution *exec)
{
	t_list	*node;

	prepare_exec(exec->current->content);
	node = exec->envp;
	while (node)
	{
		if (node->content)
			printf("%s\n", (char *)node->content);
		node = node->next;
	}
}

void	execute_export(t_execution *exec)
{
	int			index;
	t_command	*cmd;
	char		**splitted;

	cmd = exec->current->content;
	if (!cmd->args)
		export_print(exec);
	else
	{
		index = 0;
		while (cmd->args[index])
		{
			splitted = ft_split(cmd->args[index], '=');
			if (!splitted)
				return ;
			ft_setenv(exec->envp, splitted[0], splitted[1]);
			free(splitted[0]);
			free(splitted[1]);
			free(splitted);
			index++;
		}
	}
}

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
