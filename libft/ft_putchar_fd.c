/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:38:44 by ngastana          #+#    #+#             */
/*   Updated: 2023/09/14 18:26:20 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* int main(int argc,char **argv)
{
    int fd2; 
    char    a;
    
    a= 'i';
    fd2=open("argv[1]",O_WRONLY | O_TRUNC| O_CREAT , 0777);
    
    printf("%d\n",fd2);
    printf("%s\n",argv[1]);
    
    write(fd2,argv[1],ft_strlen(argv[1]));
    
    int i=0;
    while(argv[2][i]!='\0')
    {
    ft_putchar_fd(argv[2][i], fd2);
    i++;
    }
} */
