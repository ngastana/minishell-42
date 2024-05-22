/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:29:17 by ngastana          #+#    #+#             */
/*   Updated: 2023/09/25 18:16:03 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

/* int	main(void)
{
	t_list	*nodo1;
	t_list	*nodo2;
	t_list	*nodo3;

	nodo1 = ft_lstnew("eder");
	nodo2 = ft_lstnew("parate");
	nodo3 = ft_lstnew("ya");
	nodo1 -> next = nodo2;
	nodo2 -> next = nodo3;
	printf(" %s ", ft_lstlast(nodo1)-> content);
}
 */