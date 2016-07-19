/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:45:51 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/07 15:41:03 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	len;
	char	*scpy;

	len = ft_strlen(s1);
	scpy = NULL;
	scpy = (char *)malloc((sizeof(*scpy) * (len + 1)));
	if (scpy != NULL)
		ft_strcpy(scpy, s1);
	return (scpy);
}
