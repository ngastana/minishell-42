/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:36:04 by ngastana          #+#    #+#             */
/*   Updated: 2023/09/14 18:26:56 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

/* int main (int   argc, char  **argv)
{
    printf("%d\n",argc);
    int fd;

    fd= open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0077);
    ft_putstr_fd(argv[2], fd);
} */