/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:02:02 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/01 11:19:26 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *s1cpy;
	unsigned char *s2cpy;

	s1cpy = (unsigned char *)s1;
	s2cpy = (unsigned char *)s2;
	while (*s1cpy == *s2cpy && *s1cpy != '\0')
	{
		s1cpy++;
		s2cpy++;
	}
	if (*s1cpy > *s2cpy || *s1cpy < *s2cpy)
		return (*s1cpy - *s2cpy);
	else
		return (0);
}
