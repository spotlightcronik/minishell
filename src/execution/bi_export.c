/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:00:53 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/03 13:58:15 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	export_print(t_execution *exec)
{
	t_list	*node;

	execute_redirs(exec->current->content);
	node = exec->envp;
	while (node)
	{
		if (node->content)
			printf("declare -x %s\n", (char *)node->content);
		node = node->next;
	}
}

static int	valid_export(char *str)
{
	int	index;

	if (!isalnum(str[0]))
	{
		ft_fprintf(2, "minishell: %s: invalid name\n", str);
		return (0);
	}
	index = 1;
	while (str[index] && str[index] != '=')
	{
		if (!isalpha(str[index]))
		{
			ft_fprintf(2, "minishell: %s: invalid name\n", str);
			return (0);
		}
		index++;
	}
	return (1);
}

static int	export_set(t_execution *exec)
{
	t_command	*cmd;
	int			index;
	int			errored;
	char		**splitted;

	cmd = exec->current->content;
	index = 0;
	errored = 0;
	while (cmd->args[index])
	{
		if (valid_export(cmd->args[index]) == 1)
		{
			splitted = ft_split(cmd->args[index], '=');
			if (!splitted)
				return (1);
			ft_setenv(exec->envp, splitted[0], splitted[1]);
			free(splitted[0]);
			free(splitted[1]);
			free(splitted);
		}
		else
			errored = 1;
		index++;
	}
	return (errored);
}

void	execute_export(t_execution *exec)
{
	t_command	*cmd;
	int			errred;

	cmd = exec->current->content;
	errred = 0;
	if (!cmd->args)
		export_print(exec);
	else
		errred = export_set(exec);
	g_global = errred;
}
