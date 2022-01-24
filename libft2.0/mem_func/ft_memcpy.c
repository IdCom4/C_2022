/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:26:32 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/08 14:42:56 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest2 = dest;
	const unsigned char	*src2 = src;

	size_t i = 0;
	while (i < n) {
		dest2[i] = src2[i];
		i++;
	}

	return (dest);
}

/*
** === MAN ft_memcpy ===
** -
** DESCRIPTION:
** -
** ft_memcpy copie les n premiers octets de la zone memoire pointee par src
** dans celle pointee par dest.
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
** ft_memcpy renvoie dest.
** -
*/
