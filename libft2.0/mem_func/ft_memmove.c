/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:16:37 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/13 14:47:37 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	unsigned char				*castedDest = dest;
	const unsigned char	*castedSrc = src;

	if (castedDest <= castedSrc) {
		for (size_t i = 0; i < n; i++)
			castedDest[i] = castedSrc[i];
	}
	else {
		for (n; n > 0; n--)
			castedDest[n - 1] = castedSrc[n - 1];
	}

	return (castedDest);
}

/*
** === MAN ft_memmove ===
** -
** DESCRIPTION:
** -
** ft_memmove copie les n premiers octets de src dans dest, en tenant compte
** de la potentielle superposition des deux zones memoires.
** -
** ARGUMENTS:
** -
** [void *dest]:
** un pointeur sur la zone memoire dans laquelle copier.
** [const void *src]:
** un pointeur sur la zone memoire a copier.
** [size_t n]:
** le nombre d'octet a copier.
** -
** RETOUR:
** -
** [void *]:
** ft_memmove renvoie dest.
** -
*/
