/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:03:12 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/10 21:44:20 by emunoz           ###   ########.fr       */
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
	free(matrix);
	matrix = NULL;
}

void	ft_clean(t_mini *mini)
{
	ft_clear(mini->enviroment);
	ft_clear(mini->export);
	ft_clear_token(&mini->token);
	free(mini);
}
