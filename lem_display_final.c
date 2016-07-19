/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_display_final.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:02:43 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/21 20:08:21 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*swap_id_room(t_lem *s, t_room **r, int line, int col)
{
	t_room	*tmp;

	tmp = *r;
	while (tmp != NULL)
	{
		if (tmp->index == s->pa_tab[line][col])
			return (tmp->name);
		tmp = tmp->next;
	}
	return (tmp->name);
}

static void	option_show(t_lem *s)
{
	int i;

	i = s->count_lap + 1;
	if (s->flags & OPTION_SHOW)
	{
		ft_printf("\n===========================\033[35;1m LAP %d ", i);
		ft_printf("\033[0m========================\n");
	}
}

void		lem_display_final(t_lem *s, t_room **r)
{
	int line;
	int col;

	col = s->pa_tab[s->count_path - 1][0];
	if (!(s->flags & PRINT_FILE))
	{
		ft_printf("%s\n\n", s->file);
		ft_set_bit(&(s->flags), PRINT_FILE);
	}
	option_show(s);
	while (col > 1)
	{
		line = 0;
		while (line < s->count_path)
		{
			if ((s->f = s->hex_tab[line][col]) != 0)
			{
				if (line > s->l)
					s->l = line;
				ft_printf("L%d-%s ", s->f, swap_id_room(s, r, line, col));
			}
			line++;
		}
		col--;
	}
}
