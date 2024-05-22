/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:45:43 by ngastana          #+#    #+#             */
/*   Updated: 2023/09/27 20:41:17 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}	
	ft_lstlast(*lst)-> next = new;
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
	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);
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
}
 */