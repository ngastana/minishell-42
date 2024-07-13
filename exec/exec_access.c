/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:59:42 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/13 12:34:28 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_handle_error(t_mini *cur_mini, char *aux, int i)
{
	free(cur_mini->path);
	if (cur_mini->location_paths[i] == NULL && cur_mini->token->type != T_DLESS)
	{
		g_status = 127;
		printf("%s: command not found\n", aux);
		free(aux);
		ft_clear(cur_mini->location_paths);
		return (0);
	}
	ft_clear(cur_mini->location_paths);
	free(aux);
	return (1);
}

static int	ft_access(char *aux, char *loc, char *tmp, t_mini *mini)
{
	if (access(loc, X_OK) == 0)
	{
		free(aux);
		ft_clear(mini->comands);
		free(mini->path);
		ft_clear(mini->location_paths);
		free(tmp);
		free(loc);
		return (1);
	}
	return (0);
}

static int	ft_path_error(char *aux, t_mini *cur_mini)
{
	if (!cur_mini->path)
	{
		g_status = 127;
		printf("%s: Not such file or directory\n", cur_mini->comands[0]);
		ft_clear(cur_mini->comands);
		free(aux);
		return (0);
	}
	return (1);
}

int	ft_is_command(t_mini *cur_mini)
{
	char	*location;
	char	*tmp;
	char	*aux;
	int		i;

	i = 0;
	aux = ft_get_comands(cur_mini->token);
	cur_mini->comands = ft_split(aux, ' ');
	cur_mini->path = ft_find_path(cur_mini->enviroment);
	if (ft_path_error(aux, cur_mini) == 0)
		return (0);
	cur_mini->location_paths = ft_split(cur_mini->path, ':');
	while (cur_mini->location_paths[i] != NULL)
	{
		tmp = ft_strjoin(cur_mini->location_paths[i], "/");
		if (cur_mini->comands)
			location = ft_strjoin(tmp, cur_mini->comands[0]);
		if (ft_access(aux, tmp, location, cur_mini) == 1)
			return (1);
		i++;
		free(tmp);
		free(location);
	}
	ft_clear(cur_mini->comands);
	return (ft_handle_error(cur_mini, aux, i));
}
