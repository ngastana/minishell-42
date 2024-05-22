/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:50:10 by ngastana          #+#    #+#             */
/*   Updated: 2023/09/15 19:14:07 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*str2;
	char			*str3;

	str2 = (char *) src;
	str3 = (char *) dest;
	i = 0;
	if (str2 == str3 || n == 0)
		return (dest);
	while (i < n)
	{
		str3[i] = str2[i];
		i++;
	}
	dest = str3;
	return (dest);
}

/* int	main()
{
	char dest[3] = "42";
	char src[4] = "pep";

	ft_memcpy(dest, src, 7);
	printf("%s\n", dest);
	return (0);
} */
