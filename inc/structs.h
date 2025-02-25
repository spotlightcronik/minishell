/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:59:36 by auloth            #+#    #+#             */
/*   Updated: 2025/02/25 11:49:26 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "a_minishell.h"

typedef struct s_token
{
	char		*type;
	char		*content;
}				t_token;

typedef struct s_quotes
{
	char		type;
	int			passed;
}				t_quotes;

typedef struct s_info
{
	char		**ip;
	char		*str;
	t_quotes	q;
	t_token		*token_list;
	int			token_list_size;
	int			count;
	t_list		*env_param;
	t_list		*action_list;
	int			dollar_signs;
	int			initialize;
}				t_info;

#endif
