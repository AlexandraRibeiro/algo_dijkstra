/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 17:42:46 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/22 14:05:49 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_free(t_lem *s, t_room **r)
{
	if (s->tab != NULL)
		lem_free_tab(s);
	if (s->v_tab != NULL)
		lem_free_visited_tab(s);
	if (s->pa_tab != NULL)
		lem_free_path_tab(s);
	if (s->pr_tab != NULL)
		lem_free_predecessor_tab(s);
	if (s->hex_tab != NULL)
		lem_free_hex_tab(s);
	if (*r != NULL)
		lem_free_list_room(s, r);
	if (s->line != NULL)
		ft_memdel((void **)&(s->line));
	if (s->file != NULL)
		ft_memdel((void **)&(s->file));
	if (s->nt != NULL)
		ft_memdel((void **)&(s->nt));
	if (s->stock != NULL)
		ft_memdel((void **)&(s->stock));
	get_next_line(-1, NULL);
}
