/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana <ngastana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:34:57 by ngastana          #+#    #+#             */
/*   Updated: 2024/05/21 18:10:11 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_env(char **env, t_token *token)
{
	t_token	*current;
	int		i;
	int		flag;
	
	i = 0;
	flag = 0;
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
				flag++;
			}
			current = current->next;
		}
	}
	if (flag > 0)
		g_status = 127;
	else
		g_status = 0;
	return (0);
}
