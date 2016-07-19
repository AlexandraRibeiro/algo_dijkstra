/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:45:15 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/03 18:26:26 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int number;
	int signs;

	number = 0;
	signs = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\n' ||
			*str == '\f' || *str == '\r')
		str++;
	while (*str < '0' && *str > '9')
		str++;
	if (*str == '-')
	{
		signs = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + (*str - '0');
		str++;
	}
	return (signs * number);
}
