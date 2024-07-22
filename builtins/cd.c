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

void	init_env_vars(t_mini *mini)
{
	char	*cwd;

	if (!search_in_matrix("OLDPWD", mini->enviroment))
		mini->enviroment = add_to_matrix("OLDPWD", mini->enviroment);
	if (!search_in_matrix("PWD", mini->enviroment))
	{
		cwd = getcwd(NULL, 0);
		if (cwd)
		{
			mini->enviroment = add_to_matrix(ft_strjoin("PWD=", cwd),
					mini->enviroment);
			free(cwd);
		}
	}
}

int	handle_special_cases(t_mini *mini, t_token *current)
{
	char	*oldpwd;

	if (!current || (current->value[0] == '~' && current->value[1] == '\0')
		|| (current->value[0] == '-' && current->value[1] == '-'
			&& current->value[2] == '\0'))
	{
		go_home(mini);
		return (1);
	}
	else if (current->value[0] == '-' && current->value[1] == '\0')
	{
		oldpwd = get_envlst(mini, "OLDPWD");
		if (oldpwd)
		{
			update_env(mini, "PWD", oldpwd);
			printf("%s\n", oldpwd);
			chdir(oldpwd);
		}
		else
			ft_putstr_fd("cd: OLDPWD not set\n", 2);
		g_status = 0;
		return (1);
	}
	return (0);
}

int	update_pwd_and_oldpwd(t_mini *mini)
{
	char	*cwd;
	char	*oldpwd;

	oldpwd = get_envlst(mini, "PWD");
	update_env(mini, "OLDPWD", oldpwd);
	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		update_env(mini, "PWD", cwd);
		free(cwd);
		return (0);
	}
	else
	{
		g_status = 1;
		perror("cd");
		return (1);
	}
}

int	ft_cd(t_mini *mini, t_token *current)
{
	init_env_vars(mini);
	if (handle_special_cases(mini, current))
		return (0);
	if (chdir(current->value) != 0)
	{
		g_status = 1;
		return (perror("cd"), 1);
	}
	if (update_pwd_and_oldpwd(mini) != 0)
		return (1);
	g_status = 0;
	return (0);
}

/* int	ft_cd(t_mini *mini, t_token *current)
{
	char	*cwd;
	char	*oldpwd;

	if (!search_in_matrix("OLDPWD", mini->enviroment))
		mini->enviroment = add_to_matrix("OLDPWD", mini->enviroment);
	if (!search_in_matrix("PWD", mini->enviroment))
	{
		cwd = getcwd(NULL, 0);
		if (cwd)
		{
			mini->enviroment = add_to_matrix(ft_strjoin("PWD=", cwd),
					mini->enviroment);
			free(cwd);
		}
	}
	if (!current || (current->value[0] == '~' && current->value[1] == '\0')
		|| (current->value[0] == '-' && current->value[1] == '-'
			&& current->value[2] == '\0'))
		return (go_home(mini), 0);
	else if ((current->value[0] == '-' && current->value[1] == '\0'))
	{
		oldpwd = get_envlst(mini, "OLDPWD");
		if (oldpwd)
		{
			update_env(mini, "PWD", oldpwd);
			printf("%s\n", oldpwd);
			chdir(oldpwd);
		}
		else
			ft_putstr_fd("cd: OLDPWD not set\n", 2);
		g_status = 0;
		return (0);
	}
	if (chdir(current->value) != 0)
	{
		g_status = 1;
		return (perror("cd"), 1);
	}
	update_env(mini, "OLDPWD", get_envlst(mini, "PWD"));
	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		update_env(mini, "PWD", cwd);
		free (cwd);
	}
	else
	{
		g_status = 1;
		return (perror ("cd"), 1);
	}
	g_status = 0;
	return (0);
} */
