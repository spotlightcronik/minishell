/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:41:36 by auloth            #+#    #+#             */
/*   Updated: 2025/02/04 13:57:50 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_minishell.h"

int	check_for_comand(t_info *data)
{
	if (ft_strncmp(&data->str[data->count], "echo", word_len(data)) == 0)
		return (data->count += ft_strlen("echo"), create_token(data, "echo",
				"comand"));
	if (ft_strncmp(&data->str[data->count], "cd", word_len(data)) == 0)
		return (data->count += ft_strlen("cd"), create_token(data, "cd",
				"comand"));
	if (ft_strncmp(&data->str[data->count], "pwd", word_len(data)) == 0)
		return (data->count += ft_strlen("pwd"), create_token(data, "pwd",
				"comand"));
	if (ft_strncmp(&data->str[data->count], "export", word_len(data)) == 0)
		return (data->count += ft_strlen("export"), create_token(data, "export",
				"comand"));
	if (ft_strncmp(&data->str[data->count], "unset", word_len(data)) == 0)
		return (data->count += ft_strlen("unset"), create_token(data, "unset",
				"comand"));
	if (ft_strncmp(&data->str[data->count], "env", word_len(data)) == 0)
		return (data->count += ft_strlen("env"), create_token(data, "env",
				"comand"));
	if (ft_strncmp(&data->str[data->count], "exit", word_len(data)) == 0)
		return (data->count += ft_strlen("exit"), create_token(data, "exit",
				"comand"));
	return (0);
}
