/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_without_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:23:41 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/11 15:10:29 by emunoz           ###   ########.fr       */
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

int	ft_without_token(char **input, t_token **token)
{
	char	*tmp_input;
	//char 	**input_2;
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
	if (mark != 0)
		value = ft_substr(tmp_input, 1, i -2);
	else
		value = ft_substr(tmp_input, 0, i);
	tmp_input = NULL;
	if (!value)
		return (0);
	new_token = ft_add_new_token(value, mark, T_IDENTIFIER);
	if (!new_token)
		return (free(value), 0);
	//input_2 = &input[i];
	*input += i;
	return (ft_add_token(token, new_token), 1);
}
