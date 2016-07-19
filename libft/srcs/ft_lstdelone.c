/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 16:00:11 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/11 23:02:05 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && del != NULL && *alst != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		if (*alst != NULL)
		{
			free(*alst);
			*alst = NULL;
		}
	}
}
