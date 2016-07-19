/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 18:43:49 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/21 21:49:27 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

MY_LLINT	lem_atoi(const char *str, t_lem *s)
{
	MY_LLINT	number;
	int			signs;

	number = 0;
	signs = 1;
	if (s->flags & VALID_ANT)
	{
		if (*str == '-')
		{
			signs = -1;
			str++;
		}
		else if (*str == '+')
			str++;
	}
	if (*str == '\0' || *str < '0' || *str > '9')
		return (-2147483650);
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		number = (number * 10) + (*str - '0');
		str++;
	}
	if (*str != '\0')
		return (-2147483650);
	return (signs * number);
}
