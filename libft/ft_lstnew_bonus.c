/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:57:08 by ngastana          #+#    #+#             */
/*   Updated: 2023/09/25 17:43:40 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*q;

	q = (t_list *) malloc(sizeof(t_list));
	if (q == NULL)
		return (NULL);
	q -> content = content;
	q -> next = NULL;
	return (q);
}

/* int	main(void)
{
	char	*content;
	t_list	*q;

	content = "hola mano";
	q = ft_lstnew(content);
	printf("%s", q -> content);
}
 */