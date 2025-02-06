/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:59:10 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/06 15:41:58 by jeperez-         ###   ########.fr       */
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

typedef int		t_fd;
typedef t_fd	t_pipe[2];

void	execute_line(t_list *lst, t_list *envp);
void	prepare_exec(t_command cmd);
pid_t	execute_builtin(t_command *cmd, t_fd in, t_fd out, t_list *envp);

void	free_cmd(void *cmd);

char	*ft_getenv(t_list *envp, char *env_name);
int		ft_setenv(t_list *envp, char *env_name, char *value);
t_list	*ft_envp_node(t_list *envp, char *env_name);

#endif
