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

int	ft_count_pipex(t_mini *mini)
{
	t_token	*tmp_token;
	int		i;

	tmp_token = mini->token;
	i = 0;
	while (tmp_token)
	{
		if (tmp_token->type == T_PIPE)
			i++;
		tmp_token = tmp_token->next;
	}
	return (i);
}

char	*ft_find_path(char **envp)
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

char	*ft_get_comands(t_token *cur_token)
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

void	ft_special_cases(t_mini *cur_mini, int ostdout, int ostdin)
{
	while (cur_mini->token && cur_mini->token->type != T_PIPE)
		cur_mini->token = cur_mini->token->next;
	if (cur_mini->token && cur_mini->token->type == T_PIPE)
		cur_mini->token = cur_mini->token->next;
	dup2(ostdout, STDOUT_FILENO);
	dup2(ostdin, STDIN_FILENO);
}
