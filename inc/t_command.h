/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_command.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:48:17 by jeperez-          #+#    #+#             */
/*   Updated: 2025/01/28 15:51:04 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_COMMAND_H
# define T_COMMAND_H

typedef struct s_command
{
	char	*infile;
	char	heredoc;
	char	*name;
	char	**args;
	char	*output;
	bool	append;
}	t_command;

#endif
