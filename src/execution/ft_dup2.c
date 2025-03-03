/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:07:33 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/27 17:38:43 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

t_fd	ft_dup2(t_fd oldfd, t_fd newfd)
{
	t_fd	ret;

	ret = dup2(oldfd, newfd);
	if (ret == -1)
		ft_fprintf(2, "minishell: dup2 failed\n");
	else
	{
		if (oldfd != newfd)
			close(oldfd);
	}
	return (ret);
}
