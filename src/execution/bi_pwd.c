/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:12:29 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/27 18:38:59 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	execute_pwd(t_execution *exec)
{
	char	*pwd;

	if (execute_redirs(exec->current->content) == -1)
	{
		g_global = 1;
		return ;
	}
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		g_global = 2;
		return ;
	}
	printf("%s\n", pwd);
	free(pwd);
	g_global = 0;
}
