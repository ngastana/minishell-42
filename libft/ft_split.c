/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana < ngastana@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:03:20 by ngastana          #+#    #+#             */
/*   Updated: 2024/07/13 12:20:41 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

void	clear(char **matrix)
{
	int	m;

	m = 0;
	while (matrix[m] != NULL)
	{
		free (matrix[m]);
		m++;
	}
	free (matrix);
}

static	int	differents(char const *s, char c)
{
	int	divisor;
	int	i;

	divisor = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == c) && (s[i] != '\0'))
			i++;
		while ((s[i] != c) && (s[i] != '\0'))
			i++;
		if ((s[i -1]) == c)
			divisor = divisor -1;
		divisor++;
	}
	return (divisor);
}

char	**fill(char **matrix, const char *s, char c)
{
	int		j;
	int		m;
	int		len;

	m = 0;
	j = 0;
	while (s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		if (s[j] == '\0')
			return (matrix);
		len = count(s + j, c);
		matrix[m] = ft_substr(s, j, len);
		if (!matrix[m])
		{
			clear(matrix);
			return (NULL);
		}
		j = j + len;
		m++;
	}
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;

	if (s == NULL)
		return (NULL);
	matrix = malloc(sizeof(char *) * (differents(s, c) + 1));
	if (matrix == NULL)
		return (NULL);
	matrix[differents(s, c)] = NULL;
	return (fill (matrix, s, c));
}

/* int	main(void)
{
	char const	*s;
	char		**split;
	int			i;

	s = "    hola \0  manolito   gafotas   ";
	printf("%i\n", diferentes(s, ' '));
	printf("%i\n", count(s, ' '));
 	split = ft_split(s, '\0');
	i = 0;
	while (split[i] != NULL)
	{
		printf("%s\n", split[i]);
		i++;
	}
} */
