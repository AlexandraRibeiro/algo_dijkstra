/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdupall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 13:32:23 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/13 13:32:34 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstdupall(t_list *lst)
{
	t_list	*start;
	t_list	*move;

	start = NULL;
	move = NULL;
	if (lst == NULL)
		return (NULL);
	start = ft_lstnew(lst->content, lst->content_size);
	if (start == NULL)
		return (NULL);
	move = start;
	lst = lst->next;
	while (lst != NULL)
	{
		move->next = ft_lstnew(lst->content, lst->content_size);
		if (move->next == NULL)
			return (NULL);
		move = move->next;
		lst = lst->next;
	}
	return (start);
}
