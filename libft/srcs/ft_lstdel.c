/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 16:18:37 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/11 23:37:32 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *alstmem;

	alstmem = *alst;
	if (del != NULL && alst != NULL)
	{
		while (alstmem != NULL)
		{
			del(alstmem->content, alstmem->content_size);
			if (alstmem != NULL)
			{
				free(alstmem);
				alstmem = alstmem->next;
			}
		}
		*alst = NULL;
	}
}
