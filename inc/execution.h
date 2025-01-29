/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:59:10 by jeperez-          #+#    #+#             */
/*   Updated: 2025/01/28 16:56:51 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "inc/t_command.h"
# include "lib/libft/inc/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef int fd_t;

typedef struct s_execution
{
	fd_t in_fd;
}	t_execution;

#endif
