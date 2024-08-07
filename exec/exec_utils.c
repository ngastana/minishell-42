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

char	*find_path(char **envp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp && ft_strncmp("PATH", envp[i], 4))
		i++;
	while (envp && envp[j] != NULL)
		j++;
	if (i == 0 || i == j)
		return (NULL);
	return (ft_strdup(envp[i] + 5));
}

char	*get_comands(t_token *cur_token)
{
	char	*str1;
	char	*temp;
	t_token	*token;

	token = cur_token;
	str1 = ft_strdup(token->value);
	while (token->next && (token->next->type == T_IDENTIFIER
			|| token->next->type == T_LESS))
	{
		token = token->next;
		if (token->next && token->type == T_LESS)
			token = token->next;
		temp = str1;
		str1 = ft_strjoin(str1, " ");
		free(temp);
		temp = str1;
		str1 = ft_strjoin(str1, token->value);
		free(temp);
	}
	if (token->next)
		token = token->next;
	return (str1);
}

static int	ft_is_command_utils(t_mini *cur_mini, char *aux, int i)
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

int	is_command(t_mini *cur_mini)
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
	if (!cur_mini->path)
	{
		g_status = 127;
		printf("%s: Not such file or directory\n", cur_mini->comands[0]);
		ft_clear(cur_mini->comands);
		free(aux);
		return (0);
	}
	cur_mini->location_paths = ft_split(cur_mini->path, ':');
	while (cur_mini->location_paths[i] != NULL)
	{
		tmp = ft_strjoin(cur_mini->location_paths[i], "/");
		if (cur_mini->comands)
			location = ft_strjoin(tmp, cur_mini->comands[0]);
		if (access(location, X_OK) == 0)
		{
			free(aux);
			ft_clear(cur_mini->comands);
			free(cur_mini->path);
			ft_clear(cur_mini->location_paths);
			free(tmp);
			free(location);
			return (1);
		}
		i++;
		free(tmp);
		free(location);
	}
	ft_clear(cur_mini->comands);
	return (ft_is_command_utils(cur_mini, aux, i));
}
