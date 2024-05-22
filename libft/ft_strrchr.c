/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:34:02 by ngastana          #+#    #+#             */
/*   Updated: 2023/09/18 18:01:50 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (0);
}

/* int main()
{
	char	*s= "tanolito";

	printf("strrchr(s, 't'))%s\n",strrchr(s, 't'));
	printf("ft_strrchr(s, 't'))%s",ft_strrchr(s, 't'));
} 
  */