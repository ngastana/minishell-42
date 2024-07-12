/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:17:13 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/11 14:40:06 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_sigint(int sig)
{
	(void) sig;
	ft_putstr_fd("\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handle_sigint_2(int sig)
{
	(void) sig;
	ft_putstr_fd("\n", 1);
}

void	handle_sigquit(int sig)
{
	(void)sig;
}

void	handle_eof(t_mini *mini, char *input)
{
	printf("exit\n");
	ft_clear(mini->enviroment);
	ft_clear(mini->export);
	ft_clear_token(&mini->token);
	free(input);
	free(mini);
	rl_clear_history();
	exit(EXIT_SUCCESS);
}

void	signal_handlers(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
