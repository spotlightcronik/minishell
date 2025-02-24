/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:00:22 by auloth            #+#    #+#             */
/*   Updated: 2025/02/24 19:16:54 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

void handle_sigint(int sig)
{
	(void)sig;  // Ignore the parameter
    printf("\n");  // Move to a new line
    rl_replace_line("", 0);  // Clear the current input buffer
    rl_on_new_line();  // Reset readline to start a new line
    rl_redisplay();  // Redisplay the prompt
}

void handle_sigquit(int sig)
{
	(void)sig;
}

void init_signals(void)
{
	signal(SIGINT, handle_sigint);   // Ctrl-C
    signal(SIGQUIT, handle_sigquit); // Ctrl
}
