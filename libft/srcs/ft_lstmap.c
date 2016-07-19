/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:57:11 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/12 20:05:27 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*start;
	t_list	*move;

	start = NULL;
	move = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	start = ft_lstnew(lst->content, lst->content_size);
	if (start == NULL)
		return (NULL);
	start = f(start);
	move = start;
	lst = lst->next;
	while (lst != NULL)
	{
		move->next = ft_lstnew(lst->content, lst->content_size);
		if (move->next == NULL)
			return (NULL);
		move->next = f(move->next);
		move = move->next;
		lst = lst->next;
	}
	return (start);
}
