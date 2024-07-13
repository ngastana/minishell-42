/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:59:42 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/13 20:46:54 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	ft_child_utils(t_mini *cur_mini)
{
	int		i;
	char	*location;
	char	*tmp;

	i = 0;
	while (cur_mini->location_paths[i] != NULL)
	{
		tmp = ft_strjoin(cur_mini->location_paths[i], "/");
		if (cur_mini->token->type != T_DLESS)
			location = ft_strjoin(tmp, cur_mini->comands[0]);
		else
			location = (char *)ft_calloc(sizeof(char), 1);
		if (access(location, X_OK) == 0)
		{
			if (execve(location, cur_mini->comands, cur_mini->enviroment) == -1)
			{
				printf("Error execve\n");
				g_status = 127;
			}
			free(location);
			free(tmp);
			ft_clear(cur_mini->comands);
			return (1);
		}
		i++;
		free(location);
		free(tmp);
	}
	return (0);
}

void	ft_child(t_mini *cur_mini)
{
	char	*aux;

	aux = get_comands(cur_mini->token);
	cur_mini->comands = ft_split(aux, ' ');
	cur_mini->path = find_path(cur_mini->enviroment);
	cur_mini->location_paths = ft_split(cur_mini->path, ':');
	if (ft_child_utils(cur_mini) == 1)
		return ;
	if (cur_mini->location_paths)
		ft_clear(cur_mini->location_paths);
	if (cur_mini->path)
		free(cur_mini->path);
	free (aux);
	ft_clear(cur_mini->comands);
	return ;
}

void	ft_fork(t_mini *cur_mini)
{
	pid_t	pid;

	pid = fork();
	signal(SIGINT, handle_sigquit);
	if (pid == -1)
		return ;
	else if (pid == 0)
	{
		ft_child(cur_mini);
		exit (EXIT_SUCCESS);
	}
	else
		waitpid(pid, &g_status, 0);
	if (g_status == 256)
		g_status = 1;
	else if (g_status == 2)
		g_status = 130;
	signal_handlers();
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

void	create_child(t_mini *cur_mini)
{
	int		original_stdout;
	int		original_stdin;
	int		count_pipex;

	count_pipex = 0;
	original_stdout = dup(STDOUT_FILENO);
	original_stdin = dup(STDIN_FILENO);
	while (count_pipex <= cur_mini->nbr_pipex)
	{
		if (!do_redirection(cur_mini, count_pipex))
			return ;
		if (cur_mini->token->type == T_GREAT || cur_mini->token->type == T_LESS)
			cur_mini->token = cur_mini->token->next->next;
		if (cur_mini->token && cur_mini->token->type == T_DLESS
			&& cur_mini->token->next->next)
			cur_mini->token = cur_mini->token->next->next;
		if (cur_mini->token && ft_is_builtin(cur_mini->token->value))
			ft_exec_builtin(cur_mini, cur_mini->token);
		else if (cur_mini->token && is_command(cur_mini))
			ft_fork(cur_mini);
		ft_special_cases(cur_mini, original_stdout, original_stdin);
		count_pipex++;
	}
	return (close(original_stdout), close(original_stdin), (void)0);
}

static int	count_pipex(t_mini *mini)
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

void	exec(t_mini *mini)
{
	t_mini	*cur_mini;
	t_token	*tmp_token;

	cur_mini = mini;
	cur_mini->nbr_pipex = count_pipex(cur_mini);
	tmp_token = cur_mini->token;
	create_child(cur_mini);
	cur_mini->token = tmp_token;
	if (!ft_compare(cur_mini->token->value, "cat")
		|| !ft_compare(cur_mini->token->value, "grep"))
		printf("\n");
	return ;
}
