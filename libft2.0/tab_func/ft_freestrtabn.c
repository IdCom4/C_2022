/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrtabn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:00:59 by idcornua          #+#    #+#             */
/*   Updated: 2019/07/12 14:37:04 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freestrtabn(char **tab, size_t size, int freeMainTab)
{

	if (!tab || size == 0)
		return ;

	for (int i = 0; i < size && tab[i]; i++) {
		free(tab[i]);
		tab[i] = NULL;
	}

	if (freeMainTab)
		free(tab);

}

/*
** === MAN ft_freestrtabn ===
** -
** DESCRIPTION:
** -
** ft_freestrtabn libere la memoire prealablement dynamiquement allouee de
** chaque chaine de caracteres pointees par tab, puis, selon fullf, tab lui
** meme.
** -
** ARGUMENTS:
** -
** [char **tab]:
** un pointeur sur la premiere chaine de caracteres a liberer.
** [size_t size]
** le nombre de chaines de caracteres pointee par tab.
** [int fullf]
** in int permettant de choisir de liberer tab lui meme, ou non.
** -
** RETOUR:
** -
** [void]
** -
*/
