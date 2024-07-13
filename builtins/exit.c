/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:59:42 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/13 18:53:36 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_exit(t_mini *mini)
{
	int x;
	x = 0;
	ft_putstr_fd("exit\n", 1);
	if (mini->token->next)
		x = ft_atoi(mini->token->next->value);
	ft_clean(mini);
	rl_clear_history();
	exit (x);
}
