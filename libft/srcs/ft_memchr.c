/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:02:17 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/07 16:30:51 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*scpy;
	unsigned char	ccpy;
	size_t			i;

	scpy = (unsigned char *)s;
	ccpy = c;
	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			if (scpy[i] == ccpy)
				return ((void *)&scpy[i]);
			i++;
		}
	}
	return (NULL);
}
