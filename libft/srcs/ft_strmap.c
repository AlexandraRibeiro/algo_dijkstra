/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 12:26:16 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/09 16:50:16 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f) (char))
{
	size_t	i;
	char	*new;

	i = 0;
	new = NULL;
	new = ft_strnew(ft_strlen(s));
	if (s != NULL && *s != '\0' && f != NULL && new != NULL && *f)
	{
		while (s[i] != '\0')
		{
			new[i] = f(s[i]);
			i++;
		}
	}
	return (new);
}
