/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:26:43 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/13 11:13:29 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	has_redirection_utils(t_mini *mini, t_token *current_token)
{
	if (current_token->type == T_DGREAT && current_token->next)
	{
		mini->outfile = open(current_token->next->value,
				O_CREAT | O_APPEND | O_RDWR, 0777);
		if (mini->outfile < 0)
			return (printf("Error outfile: %s\n", strerror(errno)), 0);
	}
	else if (current_token->type == T_LESS && current_token->next)
	{
		mini->infile = open(current_token->next->value, O_RDONLY);
		if (mini->infile < 0)
			return (printf("Error infile: %s\n", strerror(errno)), 0);
	}
	return (1);
}

int	has_redirection(t_mini *mini)
{
	t_token	*current_token;

	current_token = mini->token;
	mini->outfile = STDOUT_FILENO;
	mini->infile = STDIN_FILENO;
	while (current_token && current_token->type != T_PIPE)
	{
		if (current_token->type == T_GREAT && current_token->next)
		{
			mini->outfile = open(current_token->next->value,
					O_TRUNC | O_CREAT | O_RDWR, 0777);
			if (mini->outfile < 0)
				return (printf("Error outfile: %s\n", strerror(errno)), 0);
		}
		else if (has_redirection_utils(mini, current_token) == 0)
			return (0);
		current_token = current_token->next;
	}
	return (1);
}

int do_redirection(t_mini *mini, int count_pipex)
{
	if (!has_redirection(mini))
		return (0);
	if (count_pipex < mini->nbr_pipex)
		if (pipe(mini->fd) < 0)
			return(printf("Error doing pipe\n"), 0);
	if (mini->outfile > 1)
	{
		dup2(mini->outfile, STDOUT_FILENO);
		close(mini->outfile);
	}
	else if (mini->nbr_pipex != count_pipex)
	{
		dup2(mini->fd[1], STDOUT_FILENO);
		close(mini->fd[1]);
	}
	if (mini->infile > 1)
	{
		dup2(mini->infile, STDIN_FILENO);
		close(mini->infile);
	}
	else if (count_pipex != 0)
	{
		dup2(mini->fd[0], STDIN_FILENO);
		close(mini->fd[0]);
	}
	return (1);
}
