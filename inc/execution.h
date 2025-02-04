/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:59:10 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/04 13:50:09 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "t_command.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef int fd_t;
typedef fd_t pipe_t[2];

typedef struct s_execution
{
	fd_t	in_fd;
	char	*cmd_path;
	fd_t	out_fd;
}			t_execution;

void	execute_line(t_list *lst, t_list *envp);
void	prepare_exec(t_command cmd, t_execution *exec);

void	free_cmd(void *cmd);

#endif
