/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:57:55 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/13 13:28:25 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if ((new = (t_list *)ft_memalloc(sizeof(t_list))) != NULL)
	{
		if (content != NULL)
		{
			if ((new->content = ft_memalloc(content_size)) != NULL)
			{
				new->content = ft_memcpy(new->content, content, content_size);
				new->content_size = content_size;
			}
			else
			{
				ft_memdel((void **)&new);
				return (NULL);
			}
		}
		else
		{
			new->content = NULL;
			new->content_size = 0;
		}
		new->next = NULL;
	}
	return (new);
}
