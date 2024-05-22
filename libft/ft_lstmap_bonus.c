/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:05:09 by ngastana          #+#    #+#             */
/*   Updated: 2023/09/28 19:06:57 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*node;
	void	*content;

	if (!lst)
		return (NULL);
	newlist = NULL;
	while (lst != NULL)
	{
		content = (*f)(lst -> content);
		node = ft_lstnew(content);
		if (!node)
		{
			(*del)(content);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, node);
		lst = lst -> next;
	}
	return (newlist);
}

/* void	del(void *content)
{
	content = NULL;
}

void	f(void *content)
{
	int	i;

	while ((content + i) != '\0')
	{
		(content + i) = content + (i +1);
		i++;
	}
}

int	main(void)
{
	t_list	*nodo1;
	t_list	*nodo2;
	t_list	*nodo3;
	t_list	*lst;

	nodo1 = ft_lstnew("manolito");
	nodo2 = ft_lstnew("te");
	nodo3 = ft_lstnew("amo");
	lst = nodo1;
	lst = ft_lstmap(lst, (*f), (*del));
	while (lst -> next)
	{
		printf("%s  ", lst->content);
		lst = lst -> next;
	}
}
 */