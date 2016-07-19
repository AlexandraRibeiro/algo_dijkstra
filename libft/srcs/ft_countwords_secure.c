/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords_secure.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:15:57 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/12 19:35:13 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords_secure(char const *str, char c)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (0);
	if (str[0] == '\0')
		return (i);
	if (str[0] != c)
		i++;
	while (str[j] != '\0')
	{
		while (str[j] != c && str[j] != '\0')
		{
			if (j > 0 && str[j - 1] == c)
				i++;
			j++;
		}
		while (str[j] == c)
			j++;
	}
	return (i);
}
