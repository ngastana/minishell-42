/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:25:21 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/13 13:25:47 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
		else if (!ft_strncmp(input, "<", 1) || !ft_strncmp(input, ">", 1)
			|| !ft_strncmp(input, "|", 1) || !ft_strncmp(input, "&&", 2)
			|| !ft_strncmp(input, "(", 1) || !ft_strncmp(input, ")", 1))
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
