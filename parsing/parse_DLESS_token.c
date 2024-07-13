/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_DLESS_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:41:15 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/13 10:43:26 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	dless_function(t_token	*cur_token)
{
	if (cur_token == NULL)
	{
		g_status = 2;
		printf("syntax error near unexpected token `newline'\n");
		return (1);
	}
	while (ft_compare(readline(BOLD YELLOW "> " RESET), cur_token->value))
		write(1, "", 1);
	return (0);
}

int	parse_dless_token(t_mini *mini)
{
	t_token	*cur_token;

	cur_token = mini->token;
	while (cur_token)
	{
		if (cur_token->type == T_DLESS)
		{
			if (cur_token->next != NULL
				&& cur_token->next->type != T_IDENTIFIER)
			{
				g_status = 2;
				printf("syntax error near unexpected token `newline'\n");
				return (1);
			}
			else
			{
				cur_token = cur_token->next;
				if (dless_function(cur_token) == 1)
					return (1);
				if (cur_token->next == NULL)
					return (0);
			}
		}
		cur_token = cur_token->next;
	}
	return (0);
}
