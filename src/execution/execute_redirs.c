/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redirs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:10:34 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/27 17:32:25 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	redir_input(t_token tok)
{
	t_fd		in_fd;

	if (access(tok.content, F_OK))
	{
		ft_fprintf(2, "minishell: %s: does not exist.", tok.content);
		return (-1);
	}
	if (access(tok.content, R_OK))
	{
		ft_fprintf(2, "minishell: %s: permission denied.", tok.content);
		return (-1);
	}
	in_fd = open(tok.content, O_RDONLY);
	if (in_fd == -1)
	{
		ft_fprintf(2, "minishell: %s: is a directory\n", tok.content);
		return (-1);
	}
	else
		if (ft_dup2(in_fd, STDIN_FILENO) == -1)
			return (-1);
	return (0);
}

static int	redir_output(t_token tok)
{
	t_fd	out_fd;

	if (access(tok.content, W_OK) == -1)
	{
		ft_fprintf(2, "minishell: %s: permission denied.", tok.content);
		return (-1);
	}
	if (!ft_strcmp(tok.content, "outfile"))
	{
		while (access(tok.content, F_OK) == 0)
			unlink(tok.content);
		out_fd = open(tok.content, O_CREAT | O_WRONLY, 00644);
	}
	else
		out_fd = open(tok.content, O_CREAT | O_APPEND | O_WRONLY, 00644);
	if (out_fd == -1)
	{
		ft_fprintf(2, "minishell: %s: is a directory\n", tok.content);
		return (-1);
	}
	if (ft_dup2(out_fd, STDOUT_FILENO) == -1)
		return (-1);
	return (0);
}

static int	prepare_redirs(t_token tok)
{
	if (!ft_strcmp(tok.type, "infile")
		|| !ft_strcmp(tok.type, "heredoc"))
	{
		if (redir_input(tok) == -1)
			return (-1);
	}
	else if (!ft_strcmp(tok.type, "outfile")
		|| !ft_strcmp(tok.type, "append"))
		if (redir_output(tok) == -1)
			return (-1);
	return (0);
}

int	execute_redirs(t_command *cmd)
{
	int		index;

	if (!cmd->redir)
		return (0);
	index = 0;
	while (cmd->redir[index].type)
	{
		if (prepare_redirs(cmd->redir[index]) == -1)
			return (-1);
		index++;
	}
	return (0);
}
