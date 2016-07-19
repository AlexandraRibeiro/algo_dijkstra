/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:37:20 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/01 11:23:03 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *s1cpy;
	unsigned char *s2cpy;

	s1cpy = (unsigned char *)s1;
	s2cpy = (unsigned char *)s2;
	if (n != 0)
	{
		while (*s1cpy == *s2cpy && n != 0 && *s1cpy != '\0')
		{
			s1cpy++;
			s2cpy++;
			n--;
		}
		if (n == 0)
		{
			s1cpy--;
			s2cpy--;
			return (*s1cpy - *s2cpy);
		}
		else
			return (*s1cpy - *s2cpy);
	}
	else
		return (0);
}
