/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:42:30 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/01 16:12:10 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;
	size_t p;

	i = 0;
	p = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	if (ft_strlen(s2) > ft_strlen(s1))
		return (NULL);
	while (s1[i] != '\0')
	{
		while (s1[i + p] == s2[p])
		{
			p++;
			if (s2[p] == '\0')
				return ((char *)&s1[i]);
		}
		p = 0;
		i++;
	}
	return (NULL);
}
