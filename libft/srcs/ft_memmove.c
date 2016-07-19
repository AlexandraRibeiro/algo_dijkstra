/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:59:47 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/09 16:38:50 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *destmem;

	destmem = NULL;
	destmem = (void	*)malloc(sizeof(char) * len);
	if (destmem == NULL)
		return (NULL);
	ft_memcpy(destmem, src, len);
	ft_memcpy(dst, destmem, len);
	ft_free(destmem);
	return (dst);
}
