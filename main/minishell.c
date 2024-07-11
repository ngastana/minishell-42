/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:21:13 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/11 15:16:42 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_status = 0;

int	ft_compare(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (s1[i] != '\0' || s2[i] != '\0')
		return (1);
	return (0);
}

static void	initialize_minishell(t_mini **mini, char **env)
{
	*mini = (t_mini *)malloc(sizeof(t_mini));
	if (*mini == NULL)
	{
		perror("Failed to allocate memory for t_mini");
		exit(EXIT_FAILURE);
	}
	(*mini)->enviroment = create_matrix(env, 1);
	change_value("SHLVL=2", (*mini)->enviroment);
	(*mini)->export = create_matrix(env, 1);
}

void	take(char *input, t_mini *mini)
{
	if (!input)
	{
		ft_putstr_fd("exit\n", 1);
		ft_clean(mini);
		rl_clear_history();
		exit (1);
	}
	if (input)
		add_history(input);
}

int	main(int argc, char **argv, char **env)
{
	char	*input;
	t_mini	*mini;

	((void)argc, (void)argv);
	mini = NULL;
	initialize_minishell(&mini, env);
	signal_handlers();
	printf("PID del programa: %d\n", getpid());
	while (1)
	{
		input = readline(BOLD YELLOW "Minishell-3.2$ " RESET);
		if (input)
		{
			take(input, mini);
			mini->token = ft_token(input);
			if (!mini->token || parse(mini) == 1)
			{
				g_status = 0;
				free(input);
				ft_clear_token(&mini->token);
				continue ;
			}
			exec(mini);
			ft_clear_token(&mini->token);
			free(input);
		}
		else
			handle_eof(mini);
		ft_clear_token(&mini->token);
	}
	free(mini);
	return (0);
}
