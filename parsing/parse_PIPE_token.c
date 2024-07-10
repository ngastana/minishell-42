/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_PIPE_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:21:16 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/10 10:15:18 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parse_pipe_token(t_mini *mini)
{
	t_token	*cur_token;

	cur_token = mini->token;
	if (cur_token->type == T_PIPE)
	{
		g_status = 2;
		printf("syntax error near unexpected token `|'\n");
		return (1);
	}
	if (cur_token)
	{
		while (cur_token->next != NULL)
			cur_token = cur_token->next;
		if (cur_token->type == T_PIPE)
		{
			g_status = 2;
			printf("syntax error near unexpected token `|'\n");
			return (1);
		}
	}
	return (0);
}
