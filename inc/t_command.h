/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_command.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:48:17 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/26 11:34:21 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_COMMAND_H
# define T_COMMAND_H

typedef struct s_command
{
	char	*infile;
	char	*heredoc;
	char	*name;
	char	**args;
	char	*output;
	int		append;
}	t_command;

/*
typedef struct s_command
{
	t_token	*redic;
	char	*name;
	char	**args;
}	t_command;

t_token
{
	type = input;
	content = nombre del archivo
}

t_token
{
	type = input;
	content = nombre del archivo
}

t_token
{
	type = input;
	content = nombre del archivo
}


*/

#endif
