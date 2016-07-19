/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 16:10:54 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/13 13:52:30 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f) (t_list *elem))
{
	t_list *lstcpy;

	if (lst != NULL)
	{
		lstcpy = lst;
		while (lstcpy != NULL)
		{
			f(lstcpy);
			lstcpy = lstcpy->next;
		}
	}
}
