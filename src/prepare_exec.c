/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:10:34 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/25 15:46:34 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	heredoc_child(char *delim)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!ft_strncmp(line, delim, ft_strlen(delim))
			&& line[ft_strlen(delim)] == '\n')
		{
			free(line);
			break ;
		}
			ft_putstr_fd(line, STDOUT_FILENO);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	exit(0);
}

static void	prepare_heredoc(t_command *cmd)
{
	t_pipe	pip;
	pid_t	pid;

	if (!cmd->heredoc)
		return ;
	pipe(pip);
	pid = fork();
	if (!pid)
	{
		dup2(pip[1], STDOUT_FILENO);
		close(pip[0]);
		heredoc_child(cmd->heredoc);
	}
	dup2(pip[0], STDIN_FILENO);
	close(pip[1]);
}

static void	prepare_infile(t_command *cmd)
{
	t_fd	in_fd;

	if (!cmd->infile)
		return ;
	if (access(cmd->infile, F_OK))
		return ;
	if (access(cmd->infile, R_OK))
		return ;
	in_fd = open(cmd->infile, O_RDONLY);
	if (in_fd != -1)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
}

static void	prepare_outfile(t_command *cmd)
{
	t_fd	out_fd;

	if (!cmd->output)
		return ;
	if (!cmd->append)
	{
		while (access(cmd->output, F_OK) == 0)
			unlink(cmd->output);
		out_fd = open(cmd->output, O_CREAT | O_WRONLY, 00644);
	}
	else
		out_fd = open(cmd->output, O_CREAT | O_APPEND | O_WRONLY, 00644);
	if (out_fd != -1)
	{
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
	}
}

void	prepare_exec(t_command *cmd)
{
	if (cmd->infile)
		prepare_infile(cmd);
	if (cmd->heredoc)
		prepare_heredoc(cmd);
	if (cmd->output)
		prepare_outfile(cmd);
}
