/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:54:40 by ngastana          #+#    #+#             */
/*   Updated: 2023/10/02 19:50:06 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*a;

	while (n--)
	{
		a = ft_strrchr((char *)s, c);
	}
	s = (void *)a;
	return (0);
} */

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)c == ((unsigned char *)s)[i])
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

/* int	main()
{
	const char	*s;
	
	s = "loleloel";
	printf("%s",(char*) ft_memchr(s, 101, 8));
} 	
 */