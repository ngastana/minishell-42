/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:30:33 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/10 13:58:45 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parse(t_mini *mini)
{
	if (parse_consecutive_token(mini) == 1)
		return (1);
	if (parse_dless_token(mini) == 2)
		return (1);
	if (parser_dolar(mini) == 1)
		return (1);
	if (parse_pipe_token(mini) == 1)
		return (1);
	return (0);
}
