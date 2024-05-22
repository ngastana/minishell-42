/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:32:36 by ngastana          #+#    #+#             */
/*   Updated: 2023/09/26 18:18:54 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	(*del)(lst-> content);
	free (lst);
}

/* void	del(void *content)
{
	content = NULL;
}

int	main(void)
{
	t_list	*node1;
	t_list	*list;

	node1 = ft_lstnew("manolo");
	list = node1;
	ft_lstdelone(node1, &del);
	if (list->content == NULL)
	{
		printf("sI ");
	}
	printf("\n");
	return (0);
} */
