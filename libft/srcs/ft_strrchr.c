/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:38:41 by aribeiro          #+#    #+#             */
/*   Updated: 2015/11/30 15:14:12 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	c2;
	size_t	len;

	c2 = c;
	len = ft_strlen(s);
	while (s[len] != c2 && len != 0)
		len--;
	if (s[len] == c2)
		return (&(((char *)s)[len]));
	else
		return (NULL);
}
