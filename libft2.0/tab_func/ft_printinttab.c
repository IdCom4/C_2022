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

void	ft_printinttab(int *tab, size_t size, int print_mode)
{
	size_t i;

	if (!tab || size == 0)
		return ;
	i = 0;
	while (i < size)
	{
		if (print_mode == 0)
		{
			ft_putchar('[');
			ft_putnbr(i);
			ft_putstr("][");
			ft_putnbr(tab[i]);
			ft_putstr("]\n");
		}
		else
		{
			ft_putnbr(tab[i]);
			if (i < size - 1)
				ft_putstr(", ");
			else
				ft_putchar('\n');
		}
		i++;
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
