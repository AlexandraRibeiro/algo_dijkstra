/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 12:01:48 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/03 16:22:31 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	ptr = (char *)malloc((sizeof(*ptr) * (size + 1)));
	if (ptr != NULL)
	{
		ft_bzero(ptr, size + 1);
		return (ptr);
	}
	else
		return (NULL);
}
