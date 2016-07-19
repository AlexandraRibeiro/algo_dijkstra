/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:57:47 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/07 11:08:26 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *new;

	new = NULL;
	if (s1 != NULL || s2 != NULL)
	{
		new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (new != NULL)
		{
			new = ft_strcpy(new, s1);
			new = ft_strcat(new, s2);
		}
	}
	return (new);
}
