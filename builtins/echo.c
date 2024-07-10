/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:05:49 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/10 11:01:47 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_echo_utils(t_token *cur_token)
{
	while (cur_token != NULL)
	{
		if (cur_token->type == T_PIPE || cur_token->type == T_AND
			|| cur_token->type == T_NL)
			return ;
		if (cur_token->type != T_IDENTIFIER)
		{
			cur_token = cur_token->next;
			cur_token = cur_token->next;
			continue ;
		}
		if (ft_compare(cur_token->value, "$?"))
			g_status = 0;
		if (cur_token && !ft_compare(cur_token->value, "$?") && cur_token->next)
			printf("%d ", g_status);
		else if (cur_token && !ft_compare(cur_token->value, "$?"))
			printf("%d", g_status);
		else if (cur_token != NULL && cur_token->type == T_IDENTIFIER
			&& cur_token->next)
			printf("%s ", cur_token->value);
		else if (cur_token != NULL && cur_token->type == T_IDENTIFIER)
			printf("%s", cur_token->value);
		if (cur_token != NULL)
			cur_token = cur_token->next;
	}
}

int	ft_echo(t_token *token)
{
	t_token	*cur_token;
	int		flag;

	flag = 0;
	cur_token = token;
	cur_token = cur_token->next;
	if (cur_token && !ft_compare(cur_token->value, "-n"))
	{
		flag = 1;
		cur_token = cur_token->next;
	}
	ft_echo_utils(cur_token);
	if (flag == 0)
		printf("\n");
	return (0);
}
