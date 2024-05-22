/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:47:31 by ngastana          #+#    #+#             */
/*   Updated: 2023/09/18 20:59:58 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*resul;

	i = 0;
	j = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j -1]))
		j--;
	resul = malloc(sizeof(char) * (j - i + 1));
	if (resul == NULL)
		return (0);
	ft_memcpy(resul, s1 + i, j - i);
	resul[j - i] = '\0';
	return (resul);
}
