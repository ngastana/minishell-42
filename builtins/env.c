/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:34:57 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/10 11:06:45 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_env(char **env, t_token *token)
{
	t_token	*current;
	int		i;

	i = 0;
	g_status = 0;
	current = token;
	if (current == NULL)
		while (env[i])
			printf("%s\n", env[i++]);
	else
	{
		while (current)
		{
			if (!ft_compare(current->value, "pwd"))
				ft_pwd();
			else
			{
				printf("env: No existe el archivo o el directorio\n");
				g_status = 127;
			}
			current = current->next;
		}
	}
	return (0);
}
