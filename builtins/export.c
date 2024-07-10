/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:09:42 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/10 11:24:25 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**create_matrix(char **env, int flag)
{
	int		i;
	char	**export;

	i = 0;
	while (env[i] != NULL)
		i++;
	export = ft_calloc(sizeof(char *), (i + flag));
	i = -1;
	if (flag == 0)
		while (env[++i +1] != NULL)
			export[i] = ft_strdup(env[i]);
	else
		while (env[++i] != NULL)
			export[i] = ft_strdup(env[i]);
	return (export);
}

static void	print_export(char **export)
{
	int	i;
	int	j;

	i = -1;
	export_sort(export);
	while (export[++i])
	{
		j = 0;
		printf("declare -x ");
		while (export[i][j])
		{
			printf("%c", export[i][j]);
			if (export[i][j] == '=')
				printf("\"");
			if (export[i][j + 1] == '\0' && ft_strchr(export[i], '='))
				printf("\"");
			j++;
		}
		printf("\n");
	}
}

static void	ft_export_utils(t_mini *mini, t_token *current)
{
	if (!search_in_matrix(current->value, mini->export))
	{
		mini->export = add_to_matrix(current->value, mini->export);
		if (ft_strchr(current->value, '='))
			mini->enviroment = add_to_matrix(current->value,
					mini->enviroment);
	}
	else
	{
		change_value(current->value, mini->export);
		if (search_in_matrix(current->value, mini->enviroment))
			change_value(current->value, mini->enviroment);
		else if (ft_strchr(current->value, '='))
			mini->enviroment = add_to_matrix(current->value,
					mini->enviroment);
	}
}

int	ft_export(t_mini *mini, t_token *token)
{
	t_token	*current;

	current = token;
	g_status = 0;
	if (!token)
		return (print_export(mini->export), 0);
	else
	{
		while (current)
		{
			if (!check_value(current->value))
			{
				g_status = 1;
				current = current->next;
				continue ;
			}
			else
				ft_export_utils(mini, current);
			current = current->next;
		}
	}
	return (0);
}
