/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:32:39 by ngastana          #+#    #+#             */
/*   Updated: 2023/09/15 19:53:42 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	char			*str1;
	char			*str2;

	i = 0;
	str1 = (char *)dst;
	str2 = (char *)src;
	if (str2 == str1 || len == 0)
		return (str1);
	if (str2 < str1)
	{
		i = len;
		while (i-- > 0)
			str1[i] = str2[i];
		return (str1);
	}
	else
	{
		str1 = ft_memcpy(dst, src, len);
	}
	dst = str1;
	return (dst);
}
