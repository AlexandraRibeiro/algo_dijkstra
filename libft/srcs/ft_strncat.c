/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:31:34 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/01 12:35:42 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned char	*s1cpy;
	unsigned char	*s2cpy;
	size_t			j;
	size_t			i;

	s1cpy = (unsigned char *)s1;
	s2cpy = (unsigned char *)s2;
	j = ft_strlen(s1);
	i = 0;
	while (i < n && s2cpy[i] != '\0')
	{
		s1cpy[j] = s2cpy[i];
		j++;
		i++;
	}
	s1cpy[j] = '\0';
	return (s1);
}
