/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:29:26 by ngastana          #+#    #+#             */
/*   Updated: 2023/09/22 19:48:31 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*a;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	a = malloc((len +1) * sizeof(char));
	if (a == NULL)
		return (0);
	while (s[start] != '\0' && len > 0)
	{
		len--;
		a[i] = s[start];
		i++;
		start++;
	}
	a[i] = '\0';
	return (a);
}

/* int	main(void)
{
	char const	*s;

	s = "hola";
	printf("%s", ft_substr(s, 3, 2));
}
 */