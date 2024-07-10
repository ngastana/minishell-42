/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_DLESS_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:41:15 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/10 13:56:09 by emunoz           ###   ########.fr       */
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
	while (cur_token && cur_token->next)
	{
		if (cur_token && cur_token->type == T_DLESS)
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
					return (1);
			}
		}
		cur_token = cur_token->next;
	}
	return (0);
}
