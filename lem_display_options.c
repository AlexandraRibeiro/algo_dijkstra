/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_display_options.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:45:50 by aribeiro          #+#    #+#             */
/*   Updated: 2016/04/22 15:45:54 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	display_help_p3(void)
{
	ft_printf("\n\033[35;1m=============== OPTIONS =================\033[0m\n");
	ft_printf("\033[33;1m-v (verbose): \033[0mdetail des erreurs\n");
	ft_printf("\033[33;1m-a (add) : \033[0minformations supplementaires\n");
	ft_printf("\033[33;1m-d (detail) : \033[0mdetail des chemins trouves\n");
	ft_printf("\033[33;1m-s (show) : \033[0mmouvement des fourmis\n");
	ft_printf("\033[33;1m-h (help): \033[0mrappel du sujet (prioritaire)\n\n");
	ft_printf("Combinaisons possibles :\n");
	ft_printf("> \033[33;1m-va\033[0m ou \033[33;1m-av\033[0m\n");
	ft_printf("> \033[33;1m-vad\033[0m ou \033[33;1m-vda\033[0m\n");
	ft_printf("> \033[33;1m-vads\033[0m ou \033[33;1m-vdas\033[0m\n");
}

static void	display_help_p2(void)
{
	ft_printf("\n\033[35;1m============ ENTREE STANDARD ============\033[0m\n");
	ft_printf("Format attendu :\n");
	ft_printf(" \033[33;1mnombre_de_fourmis\n");
	ft_printf(" les_salles\n");
	ft_printf(" les_tubes\033[0m\n\n");
	ft_printf("> La definition des salles : nom coord_x coord_y\n");
	ft_printf("> La definition de la salle start : ##start\n");
	ft_printf("> La definition de la salle end : ##end\n");
	ft_printf("> La definition des tubes : nom1-nom2\n");
	ft_printf("> Le tout entre-coupe de commentaires qui commencent par #\n");
	ft_printf("> Les lignes debutant par ## sont des commandes modifiant\n");
	ft_printf("les proprietes de la ligne qui vient juste apres.\n\n");
}

void		lem_display_help(void)
{
	ft_printf("\n\033[35;1m================ OBJECTIF ===============\033[0m\n");
	ft_printf("Realiser un simulateur de 'Hex' ");
	ft_printf("\nen respectant les contraintes suivantes :\n");
	ft_printf("\n> Faire traverser la fourmiliere par n fourmis.\n");
	ft_printf("> Trouver le moyen le plus rapide.\n");
	ft_printf("> Prendre le chemin le plus court.\n");
	ft_printf("> Ne pas marcher sur ses congeneres.\n");
	ft_printf("> Eviter les embouteillages.\n");
	ft_printf("> Chaque salle ne peut contenir qu'1 seule fourmi a la fois\n");
	ft_printf("(sauf ##start et ##end).\n");
	ft_printf("\nLe but est de transferer toutes les fourmis ");
	ft_printf("\nde la salle ##start a la salle ##end");
	ft_printf("\nen un minimum de cycles.\n\n");
	display_help_p2();
	display_help_p3();
	exit(1);
}

void		lem_display_errors(char *str, t_lem *s, t_room **r)
{
	if (s->flags & ERROR_MORE)
		ft_printf("%s\n\n", s->file);
	if (s->flags & OPTION_VERBOSE)
		ft_printf("\033[31;1m%s\033[0m", str);
	else
		ft_printf("\033[31;1mERROR\033[0m\n", 2);
	lem_free(s, r);
	exit(1);
}
