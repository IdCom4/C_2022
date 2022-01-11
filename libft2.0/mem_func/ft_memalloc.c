/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:36:15 by idcornua          #+#    #+#             */
/*   Updated: 2019/06/25 10:50:55 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *mem;

	if ((mem = (void *)malloc(size)))
		ft_bzero(mem, size);
	return (mem);
}

/*
** === MAN ft_memalloc ===
** -
** DESCRIPTION:
** -
** ft_memalloc alloue dynamiquement une zone memoire de taille size.
** -
** ARGUMENTS:
** -
** [size_t size]:
** la taille de la zone memoire que l'on souhaite allouer.
** -
** RETOUR:
** -
** [void *]:
** ft_memalloc renvoie un pointeur sur le debut de la nouvelle zone memoire.
** -
*/
