/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:32:21 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/13 20:51:42 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_env(t_mini *mini, char *old_env, char *new_env)
{
	char	*new_env_str;
	int		i;

	i = 0;
	while (mini->enviroment[i]
		&& (ft_strncmp(old_env, mini->enviroment[i], ft_strlen(old_env))))
		i++;
	if (mini->enviroment[i])
	{
		new_env_str = malloc(sizeof(char) * (ft_strlen(old_env)
					+ ft_strlen(new_env) + 1));
		if (!new_env_str)
			return ;
		ft_strlcpy(new_env_str, mini->enviroment[i], ft_strlen(old_env) + 1);
		new_env_str[ft_strlen(old_env)] = '=';
		ft_strlcpy(new_env_str + ft_strlen(old_env) + 1, // leak
			new_env, ft_strlen(new_env) + 1);
		free (mini->enviroment[i]);
		mini->enviroment[i] = new_env_str;
	}
}

char	*get_envlst(t_mini *mini, char *new_env)
{
	int	i;

	i = 0;
	while (mini->enviroment[i])
	{
		if (ft_strncmp(new_env, mini->enviroment[i], ft_strlen(new_env)) == 0)
			return (mini->enviroment[i] + ft_strlen(new_env) + 1);
		i++;
	}
	return (NULL);
}

void	go_home(t_mini *mini)
{
	char	*home;

	update_env(mini, "OLDPWD", get_envlst(mini, "PWD"));
	home = get_envlst(mini, "HOME");
	if (!home)
	{
		g_status = 1;
		ft_putstr_fd("cd: HOME not set\n", 2);
		return ;
	}
	else if (chdir(home) == 0)
		update_env(mini, "PWD", home);
	g_status = 0;
}
