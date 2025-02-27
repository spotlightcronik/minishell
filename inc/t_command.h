/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_command.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:48:17 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/26 13:34:12 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_COMMAND_H
# define T_COMMAND_H

# ifndef STRUCTS_H
#  define STRUCTS_H

typedef struct s_token
{
	char	*type;
	char	*content;
}	t_token;

#endif

typedef struct s_command
{
	t_token	*redir;
	char	*name;
	char	**args;
}	t_command;

#endif
