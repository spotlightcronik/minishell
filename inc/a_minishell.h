/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:23:22 by auloth            #+#    #+#             */
/*   Updated: 2025/02/24 19:05:35 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MINISHELL
# define A_MINISHELL
# include "execution.h"
# include "libft.h"
# include "structs.h"
# include "t_command.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termcap.h>
# include <termios.h>
# include <ttyent.h>
# include <unistd.h>

int		clenup(t_info *data);
int		create_token(t_info *data, char *simbol, char *name);
int		tokenize(t_info *data);
int		stll(t_list **list, t_command *arr, int size);
int		dtll(t_list **list, char **arr);
int		ft_getenv_parse(t_info *data, int co, int insert);
int		dollar_sign(t_info *data);
int		word_len(t_info *data);
int		is_partofword(char c);
void	copy_word(t_info *data, char *new, int count);
char	**ft_realoc(char **temp);
int		add_word(t_info *data, char *word);
int		parser(t_info *data);
int		add_input(t_info *data);
int		add_redir(t_info *data, int r);
int		add_heredoc(t_info *data);
int		add_word(t_info *data, char *word);
void	set_q(t_info *data, char c);
int		clenup_parser(t_info *data);
void	init_signals(void);
#endif
