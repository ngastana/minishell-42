/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_without_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:23:41 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/13 16:28:31 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

int	ft_skip_quote(char *input, int *i)
{
	char	quote;

	quote = input[*i];
	while (ft_strchr(input + *i +1, quote))
	{
		(*i)++;
		while (input[*i] != quote)
			(*i)++;
		(*i)++;
		return (1);
	}
	return (0);
}

int	process_quotes_and_separators(char *tmp_input, int *mark, int *i)
{
	while (tmp_input[*i] && !ft_is_separator(tmp_input + *i))
	{
		if (ft_is_quote(tmp_input[*i]))
		{
			if (tmp_input[*i] == '\'')
				*mark = 1;
			else if (tmp_input[*i] == '"')
				*mark = 2;
			if (!ft_skip_quote(tmp_input, i))
			{
				g_status = 1;
				printf("Close the quotation marks\n");
				return (0);
			}
		}
		else
			(*i)++;
	}
	return (1);
}

int	create_new_token(char *tmp_input, int i, int mark, t_token **token)
{
	char	*value;
	t_token	*new_token;

	if (ft_strncmp(tmp_input, "/bin/", 5) == 0)
		value = ft_substr(tmp_input, 5, ft_strlen(tmp_input));
	else if (mark != 0)
		value = ft_substr(tmp_input, 1, i - 2);
	else
		value = ft_substr(tmp_input, 0, i);
	if (!value)
		return (0);
	new_token = ft_add_new_token(value, mark, T_IDENTIFIER);
	if (!new_token)
	{
		free(value);
		return (0);
	}
	return (ft_add_token(token, new_token), 1);
}

int	ft_without_token(char **input, t_token **token)
{
	char	*tmp_input;
	int		i;
	int		mark;

	tmp_input = *input;
	i = 0;
	mark = 0;
	if (!process_quotes_and_separators(tmp_input, &mark, &i))
	{
		ft_clear_token(token);
		return (0);
	}
	if (!create_new_token(tmp_input, i, mark, token))
		return (0);
	*input += i;
	return (1);
}

/* int	ft_without_token(char **input, t_token **token)
{
	char	*tmp_input;
	int		i;
	int		mark;
	char	*value;
	t_token	*new_token;

	tmp_input = *input;
	i = 0;
	mark = 0;
	while (tmp_input[i] && !ft_is_separator(tmp_input + i))
	{
		if (ft_is_quote(tmp_input[i]))
		{
			if (tmp_input[i] == '\'')
				mark = 1;
			else if (tmp_input[i] == '"')
				mark = 2;
			if (!(ft_skip_quote(tmp_input, &i)))
			{
				ft_clear_token(token);
				g_status = 1;
				return (printf("Close the quotation marks\n"), 0);
			}
		}
		else
			i++;
	}
	if (ft_strncmp(tmp_input, "/bin/", 5) == 0)
		value = ft_substr(tmp_input, 5, ft_strlen(tmp_input));
	else if (mark != 0)
		value = ft_substr(tmp_input, 1, i -2);
	else
		value = ft_substr(tmp_input, 0, i);
	tmp_input = NULL;
	if (!value)
		return (0);
	new_token = ft_add_new_token(value, mark, T_IDENTIFIER);
	if (!new_token)
		return (free(value), 0);
	*input += i;
	return (ft_add_token(token, new_token), 1);
}
 */