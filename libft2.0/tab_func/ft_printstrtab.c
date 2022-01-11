/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstrtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:49:27 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/24 15:01:23 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printstrtab(char **tab, int size)
{
	int i;

	if (!tab)
		return ;
	i = 0;
	if (size >= 0)
	{
		while (i < size)
		{
			ft_putstr(tab[i]);
			ft_putchar('\n');
			i++;
		}
		return ;
	}
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

/*
** === MAN ft_printstrtab ===
** -
** DESCRIPTION:
** -
** ft_printstrtab affiche sur la sortie standard le tableau de chaines de
** caracteres tab.
** -
** ARGUMENTS:
** -
** [char const **tab]:
** le tableau de chaines de caracteres a afficher.
** [int size]:
** la taille du tableau si elle doit etre specifiee, sinon mettre -1.
** -
** RETOUR:
** -
** [void]
** -
*/
