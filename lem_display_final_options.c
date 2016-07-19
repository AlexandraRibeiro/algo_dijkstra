/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_display_final_options.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 17:45:56 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/22 15:44:02 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_display_add(t_lem *s)
{
	int i;
	int nb;

	i = 0;
	ft_printf("\n\n");
	ft_printf("============================================================\n");
	ft_printf("\033[35;1m                  ADDITIONAL INFORMATION   \033[0m\n");
	ft_printf("============================================================\n");
	ft_printf("\033[33;1m Number of rooms:\033[0m %d\n", s->count_room);
	ft_printf("\033[33;1m Number of ant(s):\033[0m %d\n\n", s->ant);
	ft_printf("\033[33;1m Number of found path(s):\033[0m %d\n", s->count_path);
	while (i < s->count_path)
	{
		nb = s->pa_tab[i][0] - 1;
		ft_printf(" - The path %d goes through %d tube(s)\n", (i + 1), nb);
		i++;
	}
	ft_printf("\n\033[33;1m Number of used path(s):\033[0m");
	ft_printf(" %d / %d\n", s->l + 1, s->count_path);
	ft_printf("\033[33;1m Number of laps:\033[0m %d\n", s->count_lap);
}

void	lem_display_detail(t_lem *s, t_room **r)
{
	int i;
	int j;

	i = 0;
	ft_printf("\n\n");
	ft_printf("============================================================\n");
	ft_printf("\033[35;1m                      DETAIL PATH(S)       \033[0m\n");
	ft_printf("============================================================\n");
	ft_printf("\033[33;1m Number of found path(s):\033[0m %d\n", s->count_path);
	ft_printf("\n");
	while (i < s->count_path)
	{
		j = 2;
		ft_printf("\033[33;1m - Path %d : \033[0m", i + 1);
		while (j < (s->pa_tab[i][0] + 1))
		{
			ft_printf("%s  ", swap_id_room(s, r, i, j));
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	lem_display_show(t_lem *s, t_room **r, int line, int col)
{
	char	*sr;

	while (line < s->count_path)
	{
		col = 2;
		ft_printf("\n - Path %d : ", line + 1);
		while (col <= s->pa_tab[line][0])
		{
			sr = swap_id_room(s, r, line, col);
			if ((s->f = s->hex_tab[line][col]) != 0)
				ft_printf("\033[33;1mf%d\033[0m->%s     \t", s->f, sr);
			else
				ft_printf("\033[30;1m(empty)\033[0m->%s\t", sr);
			col++;
		}
		line++;
	}
	ft_printf("\n");
}
