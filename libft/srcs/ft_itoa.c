/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:43:20 by aribeiro          #+#    #+#             */
/*   Updated: 2015/12/08 22:29:58 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int nbr)
{
	size_t len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static char		*ft_intmin(void)
{
	char *newmin;

	newmin = NULL;
	newmin = ft_strnew(11);
	if (newmin != NULL)
		newmin = ft_strcpy(newmin, "-2147483648");
	return (newmin);
}

char			*ft_itoa(int n)
{
	char	*new;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (ft_intmin());
	new = ft_strnew(ft_intlen(n));
	i = ft_intlen(n) - 1;
	if (new != NULL)
	{
		if (n == 0)
			new[0] = '0';
		if (n < 0)
		{
			new[0] = '-';
			n = -n;
		}
		while (n > 0)
		{
			new[i] = '0' + (n % 10);
			n = n / 10;
			i--;
		}
	}
	return (new);
}
