/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:10:34 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/04 13:51:38 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	heredoc_child(char delim)
{
	char *line;

	line = get_next_line(STDIN_FILENO);
	while(line)
	{
		if (line[0] == delim && line[1] == '\n' && line[2] == 0)
			break;
		ft_putstr_fd(line, STDOUT_FILENO);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	exit(0);
}

static void	prepare_heredoc(t_command cmd, t_execution *exec)
{
	fd_t	fd;
	pid_t	pid;

	if (!cmd.heredoc)
		return ;
	fd = open("/tmp/", __O_TMPFILE | O_RDWR, 00644);
	pid = fork();
	if (!pid)
	{
		dup2(exec->in_fd, STDIN_FILENO);
		dup2(fd, STDOUT_FILENO);
		heredoc_child(cmd.heredoc);
	}
	exec->in_fd = fd;
}

static void	prepare_infile(t_command cmd)
{
	fd_t	in_fd;

	if (!cmd.infile)
		return ;
	if (access(cmd.infile, F_OK))
		return ;
	if (access(cmd.infile, R_OK))
		return ;
	in_fd = open(cmd.infile, O_RDONLY);
	if (in_fd != -1)
		dup2(in_fd, STDIN_FILENO);
}

static void	prepare_outfile(t_command cmd, t_execution *exec)
{
	fd_t	out_fd;

	if (!cmd.outfile)
		return ;
	if (!cmd.append)
	{
		while (access(cmd.outfile, F_OK) == 0)
			unlink(cmd.outfile);
		out_fd = open(cmd.outfile, O_CREAT|O_WRONLY, 00644);
	}
	else
		out_fd = open(cmd.outfile, O_CREAT|O_APPEND|O_WRONLY, 00644);
	if (out_fd != -1)
		exec->out_fd = out_fd;
}

void	prepare_exec(t_command cmd, t_execution *exec)
{
	ft_bzero(exec, sizeof(exec));
	if (cmd.infile)
		prepare_infile(cmd);
	if (cmd.heredoc)
		prepare_heredoc(cmd, exec);
	if (cmd.outfile)
		prepare_outfile(cmd, exec);
	if (exec->out_fd)
	{
		dup2(exec->out_fd, STDOUT_FILENO);
		close(exec->out_fd);
	}
}
