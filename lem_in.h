/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 10:15:15 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/21 21:49:21 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "./libft/includes/libft.h"

# define MY_LLINT	long long int

/*
** Option -v : (verbose) explain errors (ex: no path, no ant,...)
** Option -h : (help) remember the subject
** Option -a : (add) Additional information
** Option -d : (detail) Detail paths
*/
# define OPTION_VERBOSE	0x80000000
# define OPTION_ADD		0x40000000
# define OPTION_DETAIL	0x20000000
# define OPTION_SHOW	0x10000000
# define FIND_END		0x08000000
# define FIND_START		0x04000000
# define FIND_TUBE		0x02000000
# define VALID_END		0x01000000
# define VALID_START	0x00800000
# define VALID_ANT		0x00400000
# define STOP_READ		0x00200000
# define FIND_PATH		0x00100000
# define STOP_FIND_PATH	0x00080000
# define FIRST_PASS		0x00040000
# define PRINT_FILE		0x00020000
# define PRINT_END		0x00010000
# define ERROR_MORE		0x00008000

typedef struct	s_room
{
	char			*name;
	int				index;
	struct s_room	*next;
}				t_room;

typedef struct	s_lem
{
	int				**tab;
	int				**v_tab;
	int				**pa_tab;
	int				**hex_tab;
	int				*pr_tab;
	char			*line;
	char			*file;
	char			*n;
	char			*nt;
	char			*stock;
	int				f;
	int				l;
	int				t;
	int				c;
	int				flags;
	int				ret;
	int				index1;
	int				index2;
	int				count_room;
	int				count_path;
	int				count_lap;
	int				id_start;
	int				id_end;
	unsigned int	ant;
	size_t			len;
	MY_LLINT		p;
}				t_lem;

void			lem_read_check(int fd, t_lem *s, t_room **r);
void			lem_analyse_line(t_lem *s, t_room **r);
void			lem_verif_data(t_lem *s, t_room **r);
void			lem_check_ant(t_lem *s, t_room **r);
void			lem_check_start(t_lem *s, t_room **r);
void			lem_check_end(t_lem *s, t_room **r);
int				lem_check_tube(t_lem *s, t_room **r, int i, int j);
void			lem_check_room(t_lem *s, t_room **r, int cas);

int				lem_create_list_room(t_lem *s, t_room **r, char *n);
void			lem_create_tab(t_lem *s);
void			lem_fill_tab(t_lem *s);

void			lem_dijkstra_tabs(t_lem *s);
void			lem_ini_pr_tab(t_lem *s);
void			lem_ini_v_tab(t_lem *s);
void			lem_dijkstra(t_lem *s, t_room **r);
void			lem_pathfinding(t_lem *s, int i, int k, int mini);

void			lem_hex(t_lem *s, t_room **r);
void			lem_create_hex_tab(t_lem *s);
int				lem_empty_hex_tab(t_lem *s);

void			lem_free(t_lem *s, t_room **r);
void			lem_free_path_tab(t_lem *s);
void			lem_free_predecessor_tab(t_lem *s);
void			lem_free_visited_tab(t_lem *s);
void			lem_free_tab(t_lem *s);
void			lem_free_list_room(t_lem *s, t_room **r);
void			lem_free_hex_tab(t_lem *s);

MY_LLINT		lem_atoi(const char *str, t_lem *s);
void			lem_strjoin_ter(t_lem *s, char c);
void			lem_display_errors(char *str, t_lem *s, t_room **r);
void			lem_display_help(void);
void			lem_display_final(t_lem *s, t_room **r);
void			lem_display_add(t_lem *s);
void			lem_display_detail(t_lem *s, t_room **r);
void			lem_display_show(t_lem *s, t_room **r, int line, int col);
char			*swap_id_room(t_lem *s, t_room **r, int line, int col);

#endif
