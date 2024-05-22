/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:10:37 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/06 09:58:21 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cuentame(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		len;

	len = ft_cuentame(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (num == NULL)
		return (0);
	num[len] = '\0';
	if (n == 0)
		num[0] = '0';
	if (n < 0)
	{
		num[0] = '-';
		n = n * -1;
	}
	while (len != 0 && n > 0)
	{
		len--;
		num[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (num);
}
