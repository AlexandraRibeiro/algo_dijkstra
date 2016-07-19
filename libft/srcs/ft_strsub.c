/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:56:29 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/11 17:21:33 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	start2;
	size_t	l;
	int		lencpy;

	new = NULL;
	start2 = (size_t)start;
	l = ft_strlen(s);
	lencpy = (int)len;
	if (lencpy < 0 || (start2 + len) > l)
		return (NULL);
	if (s == NULL)
		return (NULL);
	if ((start2 + len) <= l)
	{
		new = ft_strnew(len);
		if (new != NULL)
			new = ft_strncpy(new, s + start, len);
	}
	return (new);
}
