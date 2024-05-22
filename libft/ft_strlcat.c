/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:56:12 by ngastana          #+#    #+#             */
/*   Updated: 2023/09/13 19:26:04 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size < ft_strlen((char *)dest))
		return (ft_strlen((char *)src) + size);
	while (dest[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0' && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	while (src[j])
	{
		i++;
		j++;
	}
	return (i);
}

/*int main ()
{
	char dest1[] = "manolo";
	char src[] = "manolito";
	char dest[14]= "a";
	
	ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
    write(1, "\n", 1);
    write(1, dest, 15);
	printf("%zu\n", ft_strlcat(dest1, src, 20));
	printf("%s\n", dest1);
	return (0);
}*/
