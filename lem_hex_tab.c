/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_hex_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 16:44:31 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/21 20:11:53 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** s->hex_tab[i][2] = first step
** column [1] empty
*/

void		lem_create_hex_tab(t_lem *s)
{
	int i;
	int len;

	i = 0;
	len = s->pa_tab[s->count_path - 1][0] + 1;
	s->hex_tab = (int **)ft_memalloc_exit(sizeof(int *) * s->count_path);
	while (i < s->count_path)
	{
		s->hex_tab[i] = (int *)ft_memalloc_exit(sizeof(int) * len);
		i++;
	}
	ft_set_bit(&(s->flags), FIRST_PASS);
}

void		lem_free_hex_tab(t_lem *s)
{
	int i;

	i = 0;
	while (i < s->count_path)
	{
		if (s->hex_tab[i] != NULL)
			free(s->hex_tab[i]);
		i++;
	}
	if (s->hex_tab != NULL)
		ft_memdel((void **)&(s->hex_tab));
}

int			lem_empty_hex_tab(t_lem *s)
{
	int col;
	int line;
	int len;

	if (s->flags & FIRST_PASS)
		return (1);
	line = 0;
	while (line < s->count_path)
	{
		col = 2;
		len = s->pa_tab[line][0] + 1;
		while (col < len)
		{
			if (s->hex_tab[line][col] != 0)
				return (1);
			col++;
		}
		line++;
	}
	return (0);
}
