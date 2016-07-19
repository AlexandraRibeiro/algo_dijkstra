/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:39:21 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/13 13:25:23 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *str2, char c2)
{
	size_t		i;
	int			j;

	i = 0;
	j = 0;
	if (str2[0] == '\0')
		return (i);
	if (str2[0] != c2)
		i++;
	while (str2[j] != '\0')
	{
		while (str2[j] != c2 && str2[j] != '\0')
		{
			if (j > 0 && str2[j - 1] == c2)
				i++;
			j++;
		}
		while (str2[j] == c2)
			j++;
	}
	return (i);
}

static char		*ft_newsub(char const *str1, char c1, size_t *p)
{
	char		*sub;
	size_t		start;
	size_t		len;
	size_t		p2;

	start = 0;
	p2 = *p;
	while (str1[p2] == c1 && str1[p2] != '\0')
		p2++;
	start = p2;
	while (str1[p2] != c1 && str1[p2] != '\0')
		p2++;
	len = p2 - start;
	*p = p2;
	sub = ft_strsub(str1, start, len);
	return (sub);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		count;
	size_t		countmem;
	size_t		pos;

	pos = 0;
	count = ft_countwords(s, c);
	tab = (char **)ft_memalloc(sizeof(char *) * (count + 1));
	if (tab == NULL)
		return (NULL);
	countmem = 0;
	while (countmem < count)
	{
		tab[countmem] = ft_newsub(s, c, &pos);
		countmem++;
	}
	return (tab);
}
