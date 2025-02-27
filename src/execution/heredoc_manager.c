/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:40:04 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/26 14:59:16 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void heredoc_read(int fd, t_token tok)
{
	char	*rl;

	rl = readline("minishell heredoc >");
	while (rl)
	{
		if (!ft_strcmp(rl, tok.content))
			break ;
		ft_putstr_fd(rl, fd);
		ft_putstr_fd("\n", fd);
		free(rl);
		rl = readline("minishell heredoc >");
	}
	free(rl);
}

static int prepare_heredoc(t_command *cmd, t_token *tok)
{
	int		fd;
	char	*filename;

	if (ft_strcmp(tok->type, "heredoc"))
		return (0);
	filename = ft_freejoin(ft_strjoin(cmd->name, tok->type), tok->content);
	if (!filename)
	{
		ft_fprintf(2, "Malloc error D:\n");
		return (-1);
	}
	fd = open(filename, O_CREAT|O_WRONLY, 00644); //to-do revise heredoc name
	if (fd == -1)
	{
		free(filename);
		ft_fprintf(2, "Error opening heredoc\n");
		return (-1);
	}
	heredoc_read(fd, *tok);
	free(tok->content);
	tok->content = filename;
	close(fd);
	return (0);
}

int	heredoc_manager(t_execution *exec)
{
	int			index;
	t_list		*node;
	t_command	*cmd;

	node = exec->current;
	while (node)
	{
		cmd = node->content;
		if (cmd->redir)
		{
			index = 0;
			while (cmd->redir[index].type)
			{
				if (!ft_strcmp(cmd->redir[index].type, "heredoc"))
					if (prepare_heredoc(cmd, &cmd->redir[index]) == -1)
						return (-1);
				index++;
			}
		}
		node = node->next;
	}
	return (0);
}

void clean_heredoc(t_execution exec)
{
	int			index;
	t_list		*node;
	t_command	*cmd;

	node = exec.current;
	while (node)
	{
		cmd = node->content;
		if (cmd->redir)
		{
			index = 0;
			while (cmd->redir[index].type)
			{
				if (!ft_strcmp(cmd->redir[index].type, "heredoc"))
				{
					while (access(cmd->redir[index].content, F_OK) == 0)
						unlink(cmd->redir[index].content);
				}
				index++;
			}
		}
		node = node->next;
	}
}
