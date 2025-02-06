/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:23:22 by auloth            #+#    #+#             */
/*   Updated: 2025/02/06 14:52:07 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MINISHELL
# define A_MINISHELL
# include "inc/t_command.h"
# include "lib/libft/inc/ft_printf_int.h"
# include "lib/libft/inc/libft.h"
# include "structs.h"
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
int		ft_getenv(t_info *data, int co, int insert);
int		dollar_sign(t_info *data);
int		word_len(t_info *data);
int		is_partofword(char c);
void	copy_word(t_info *data, char *new, int count);

#endif
