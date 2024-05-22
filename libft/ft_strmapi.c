/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:06:50 by ngastana          #+#    #+#             */
/*   Updated: 2023/09/20 12:48:35 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*a;

	i = 0;
	a = malloc(sizeof(char) * (ft_strlen(s) +1));
	if (a == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		*(a + i) = f(i, s[i]);
		i++;
	}
	a[i] = '\0';
	return (a);
}
