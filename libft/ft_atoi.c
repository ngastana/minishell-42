/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:57:04 by ngastana          #+#    #+#             */
/*   Updated: 2023/10/05 21:19:09 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	n;
	long	nb;

	i = 0;
	n = 1;
	nb = 0;
	while (str[i] == 32 || (str[i] < 14 && str[i] > 8))
	{
		i++;
	}
	if (str[i] == 43 && (str[i +1] != 43 && str[i +1] != 45))
		i++;
	if (str[i] == 45)
	{
		i++;
		n = n * -1;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = (str[i] -48) + (nb * 10);
		i++;
	}
	return ((int)(nb * n));
}
