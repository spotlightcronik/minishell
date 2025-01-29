/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:10:34 by jeperez-          #+#    #+#             */
/*   Updated: 2025/01/29 11:50:37 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	prepare_heredoc(t_command cmd, t_execution *exec)
{
	return ;
}

static void	prepare_infile(t_command cmd, t_execution *exec)
{
	fd_t	in_fd;

	if (!cmd.infile)
		return ;
	if (access(cmd.name, F_OK))
		return ;
	if (access(cmd.name, R_OK))
		return ;
	in_fd = open(cmd.name, O_RDONLY);
	if (in_fd != -1)
		exec->in_fd = in_fd;
}

static void	prepare_infile(t_command cmd, t_execution *exec)
{
	fd_t	out_fd;

	if (!cmd.outfile)
		return ;
	if (access(cmd.name, F_OK))
		return ;
	if (access(cmd.name, R_OK))
		return ;
	in_fd = open(cmd.name, O_RDONLY);
	if (in_fd != -1)
		exec->in_fd = in_fd;
}

void	execute_cmd(t_command cmd)
{
	t_execution exec;

	if (cmd.heredoc)
		prepare_heredoc(cmd, &exec);
	if (cmd.infile)
		prepare_infile(cmd, &exec);
	if (cmd.outfile)
		prepare_outfile(cmd, &exec);
}
