/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:17:13 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/09 15:56:45 by ngastana         ###   ########.fr       */
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
	printf("quit\n");
	(void)sig;
	exit(EXIT_SUCCESS);
}

void	handle_eof(t_mini *mini) 
{
	printf("exit\n");
	ft_clean(mini);
	rl_clear_history();
	exit(EXIT_SUCCESS);
}

void	signal_handlers(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
