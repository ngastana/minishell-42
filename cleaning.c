/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:03:12 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/10 19:31:05 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_del(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	ft_clear(char **matrix)
{
	int	m;

	m = 0;
	if (!matrix)
		return ;
	while (matrix[m] != NULL)
	{
		free (matrix[m]);
		m++;
	}
	free (matrix);
	matrix = NULL;
}

void	ft_clean(t_mini *mini)
{
	ft_clear(mini->enviroment);
	ft_clear(mini->export);
	ft_clear_token(&mini->token);
	free(mini);
}
