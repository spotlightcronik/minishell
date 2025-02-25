/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:59:10 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/24 19:55:33 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "t_command.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/history.h>

typedef int		t_fd;
typedef t_fd	t_pipe[2];
typedef struct s_execution
{
	t_list		*cmds;
	t_list		*current;
	t_list		*envp;
	int			size;
	int			index;
	pid_t		pid;
}	t_execution;

void	execute_line(t_list *lst, t_list *envp);
void	prepare_exec(t_command *cmd);
void	execute_builtin(t_execution *exec, t_fd in, t_fd out);
void	ft_fork(t_execution *exec, t_fd in, t_fd out);

void	execute_cmd(t_execution *exec);
void	free_cmd(void *cmd);

char	*ft_getenv(t_list *envp, char *env_name);
int		ft_setenv(t_list *envp, char *env_name, char *value);
t_list	*ft_envp_node(t_list *envp, char *env_name);

void	execute_echo(t_execution *exec);
void	execute_pwd(t_execution *exec);
void	execute_env(t_execution *exec);

void	execute_unset(t_execution *exec);
void	execute_export(t_execution *exec);
void	execute_cd(t_execution *exec);
void	execute_exit(t_execution *exec);

#endif
