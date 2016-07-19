/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:37:41 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/18 19:48:44 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc_exit(size_t size)
{
	void *ptr;

	ptr = (void *)malloc(sizeof(char) * size);
	if (ptr == NULL)
	{
		write(2, "ERROR : malloc\n", 15);
		exit(1);
	}
	ptr = ft_memset(ptr, 0, size);
	return (ptr);
}
