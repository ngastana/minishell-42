/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:56:26 by ngastana          #+#    #+#             */
/*   Updated: 2023/09/14 18:27:51 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*s;
	size_t	i;

	s = str;
	i = 0;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (s);
}

/*int	main()
{
	char	*str = "yasin";
	
	printf("%s", memset(str, 'A', 3));
}*/
