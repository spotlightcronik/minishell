/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:59:10 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/04 12:46:03 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "t_command.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>

extern int		g_global;

typedef int		t_fd;
typedef t_fd	t_pipe[2];
typedef struct s_execution
{
	t_list		*cmds;
	t_list		*current;
	t_list		**envp;
	int			size;
	int			index;
	pid_t		pid;
}	t_execution;

//execute_line.c
void	execute_line(t_list *lst, t_list **envp);

// heredoc_manager.c
int		heredoc_manager(t_execution *exec);
void	clean_heredoc(t_execution exec);

// ft_dup2.c
t_fd	ft_dup2(t_fd newfd, t_fd oldfd);

// ft_fork.c
int		ft_fork(t_execution *exec, t_fd in, t_fd out);

// execute_cmd.c
void	execute_cmd(t_execution *exec);

// execute_redirs.c
int		execute_redirs(t_command *cmd);

// execute_cmd_path.c
char	*get_cmd_path(t_command *cmd, t_list *ep_lst);

// free_funcs.c
void	free_cmd(void *cmd);

// execute_builtin.c
void	execute_builtin(t_execution *exec, t_fd in, t_fd out);

// envp_utils.c
char	*ft_getenv(t_list *envp, char *env_name);
int		ft_setenv(t_list **envp, char *env_name, char *value);
t_list	*ft_envp_node(t_list *envp, char *env_name);

// bi_print.c
void	execute_echo(t_execution *exec);
void	execute_pwd(t_execution *exec);
void	execute_env(t_execution *exec);

// bi_unset.c
void	execute_unset(t_execution *exec);

// bi_export.c
void	execute_export(t_execution *exec);

// bi_action.c
void	execute_exit(t_execution *exec);

// bi_cd.c
void	execute_cd(t_execution *exec);

// signals_child.c
void	signals_child(void);
void	signals_exec(void);

#endif
