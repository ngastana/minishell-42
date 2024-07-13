/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:25:21 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/13 20:17:32 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_process_token(char *input)
{
	if (!ft_strncmp(input, "<", 1) || !ft_strncmp(input, ">", 1)
		|| !ft_strncmp(input, "|", 1) || !ft_strncmp(input, "&&", 2)
		|| !ft_strncmp(input, "(", 1) || !ft_strncmp(input, ")", 1))
		return (0);
	return (1);
}

t_token	*ft_token(char *input)
{
	int		found;
	t_token	*token;

	found = 1;
	token = NULL;
	while (*input)
	{
		if (!found)
			return (ft_clear_token(&token), NULL);
		if (ft_space(*input))
			input = ft_skip_spaces(input);
		else if (!ft_process_token(input))
		{
			found = ft_handle_token(&input, &token);
			if (found != 1)
				g_status = 2;
		}
		else
		{
			found = ft_without_token(&input, &token);
			if (found != 1)
				g_status = 130;
		}
	}
	return (token);
}
