/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:59:42 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/09 15:39:53 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_command(t_mini *cur_mini)
{
	char	*location;
	char	*tmp;
	char	*aux;
	int		i;

	location = NULL;
	tmp = NULL;
	i = 0;
	aux = get_comands(cur_mini->token);
	cur_mini->comands = ft_split(aux, ' ');
	cur_mini->path = find_path(cur_mini->enviroment);
	cur_mini->location_paths = ft_split(cur_mini->path, ':');
	while (cur_mini->location_paths[i] != NULL)
	{
		tmp = ft_strjoin(cur_mini->location_paths[i], "/");
		location = ft_strjoin(tmp, cur_mini->comands[0]);
		if (access(location, X_OK) == 0)
			return (1);
		i++;
		free(location);
		free(tmp);
	}
	if (cur_mini->location_paths[i] == NULL)
	{
	   	g_status = 127;
		printf("%s: command not found\n", aux);
		return (0);
	}
	if (cur_mini->location_paths)
		ft_clear(cur_mini->location_paths);
	if (cur_mini->path)
		free(cur_mini->path);
	free(aux);
	ft_clear(cur_mini->comands);
	return (1);
}