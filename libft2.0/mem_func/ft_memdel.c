/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:08:30 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/12 11:16:33 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

/*
** === MAN ft_memdel ===
** -
** DESCRIPTION:
** -
** ft_memdel libere la memoire prealablement dynamiquement allouee pointee
** par *ap et met le pointeur pointé par ap a NULL.
** -
** ARGUMENTS:
** -
** [void **ap]:
** un pointeur de pointeur sur la zone memoire a liberer.
** -
** RETOUR:
** -
** [void]
** -
*/
