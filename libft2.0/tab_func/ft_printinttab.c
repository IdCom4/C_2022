/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printinttab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:40:55 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/03 15:03:42 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printinttab(int *tab, size_t size, int print_mode) {

	if (!tab || size == 0) return ;

	for (size_t i = 0; i < size; i++) {
		if (print_mode == 0) {
			// "x) [xxxxx]\n"
			const char *tabLineIndex = ft_strjoinf(ft_itoa(i), ") [", FIRST);
			const char *tabLineContent = ft_strjoinf(ft_itoa(tab[i]), "]\n", FIRST);
			const char *tabLine = ft_strjoinf(tabLineIndex, tabLineContent, ALL);

			ft_putstr(tabLine);
		}
		else {
			// xxxxx<, >\n
			const char *tabLine = ft_strjoinf(ft_itoa(tab[i]), (i < size - 1) ? ", " : "\n", FIRST);

			ft_putstr(tabLine);
		}
	}
}

/*
** === MAN ft_printinttab ===
** -
** DESCRIPTION:
** -
** ft_printinttab affiche sur la sortie standard la tableau d'int tab.
** -
** ARGUMENTS:
** -
** [int *tab]:
** le tableau d'int a afficher.
** [size__t size]:
** la taille du tableau.
** [intt print_mode]:
** un int permettant de choisir le mode d'affichage, 0 pour un affichage
** ligne par ligne, ou une autre valeur pour un affichage sur une ligne.
** -
** RETOUR:
** -
** [void]
** -
*/
