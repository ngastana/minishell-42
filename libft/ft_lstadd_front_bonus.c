/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:17:56 by ngastana          #+#    #+#             */
/*   Updated: 2023/09/25 17:37:09 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

/* int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*list;

	node1 = ft_lstnew("manolo");
	node2 = ft_lstnew("que");
	node3 = ft_lstnew("tal");
	list = node1;
	ft_lstadd_front(&list, node2);
	ft_lstadd_front(&list, node3);
	printf("List data: ");
	while (list)
	{
		printf("%s ", list -> content);
		list = list->next;
	}
	printf("\n");
	free(node1);
	free(node2);
	free(node3);
	return (0);
} */
