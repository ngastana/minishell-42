/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:18:49 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/10 12:31:12 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_strdup(const char *s)
{
	int			i;
	char		*arr;

	i = 0;
	if (s == NULL)
		return (NULL);
	arr = malloc (sizeof(char) * (ft_strlen(s) +1));
	if (!arr || arr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
