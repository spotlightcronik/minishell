/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:38:27 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/04 15:07:01 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	here_sigint(int signum)
{
	(void)signum;
	g_global = -1;
	printf("\n");
	rl_on_new_line();
	close(STDIN_FILENO);
}

void	signals_heredoc(void)
{
	signal(SIGINT, here_sigint);
}

void	signals_exec(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	signals_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
