/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:24:44 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/06 16:39:08 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	if (as) {
		free(*as);
		*as = NULL;
	}
}

/*
** === MAN ft_strdel ===
** -
** DESCRIPTION:
** -
** ft_strdel libere la chaine de caracteres prealablement dynamiquement
** allouee pointee par *as et met le pointeur pointé par as a NULL.
** -
** ARGUMENTS:
** -
** [char **as]:
** un pointeur de pointeur sur la chaine de caracteres a liberer.
** -
** RETOUR:
** -
** [void]
** -
*/
