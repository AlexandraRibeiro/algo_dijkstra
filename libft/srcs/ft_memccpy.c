/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:17:22 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/07 17:46:06 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*destcpy;
	unsigned char	*srccpy;
	unsigned char	c2;

	destcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	c2 = c;
	while (n > 0 && *srccpy != c2)
	{
		*destcpy = *srccpy;
		destcpy++;
		srccpy++;
		n--;
	}
	if (*srccpy == c2)
	{
		*destcpy = *srccpy;
		destcpy++;
		return (destcpy);
	}
	else
		return (NULL);
}
