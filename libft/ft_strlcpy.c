/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:55:57 by ngastana          #+#    #+#             */
/*   Updated: 2023/09/22 16:43:46 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t dstsize)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (src[res] != '\0')
		res++;
	if (dstsize < 1)
		return (res);
	while (src[i] != '\0' && i < dstsize -1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (res);
}

/*int main()
{
	char dest[]= "si 42 chcia guapa";
	char src[]= "fdkjjkdkljdkljdk";

	ft_strlcpy(dest, src, 7);
	printf("%s\n", dest);
	printf("%i", ft_strlcpy(dest,src,7));
	return (0);
}*/
