/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reopen_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:48:15 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/05 10:58:18 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	reopen_stdin(void)
{
	int	fd;

	if (access("/dev/tty", R_OK) == 0)
	{
		fd = open("/dev/tty", O_RDONLY);
		if (fd != -1)
		{
			if (!ft_dup2(fd, STDIN_FILENO))
				return (0);
		}
		else
			ft_fprintf(2, "minishell: open error\n");
	}
	else
		ft_fprintf(2, "minishell: No access to /dev/tty\n");
	return (-1);
}
