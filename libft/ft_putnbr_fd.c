/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:34:58 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/05 16:12:48 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd ("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd ('-', fd);
	}
	if (n > 9)
	{
		ft_putnbr_fd (n / 10, fd);
	}
	ft_putchar_fd ((n % 10) + 48, fd);
}

/* void	ft_putnbr_fd(int n, int fd)
{
	char	*s;

	s = "0123456789";
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n > 9)
		ft_putnbr_fd (n / 10, fd);
	write(fd, &s[n % 10], 1);
} */

int	main(void)
{
	ft_putnbr_fd(-21648, 1);
}
