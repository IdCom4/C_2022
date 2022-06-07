/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:43:16 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/05 15:45:20 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dest2;
	const unsigned char	*src2;

	if (!dest || !src)
		return NULL;

	while (n > 0) {
		*((char *)dest) = *((char *)src);

		if (*((char *)src) == (unsigned char)c)
			return (&dest[1]);
	
		dest2++;
		src2++;
		n--;
	}
	
	return (NULL);
}

/*
** === MAN ft_memccpy ===
** -
** DESCRIPTION:
** -
** ft_memccpy copie les n premiers octets de la zone memoire pointee par src
** dans celle pointee par dest. Si le caractere c est rencontré lors de la
** copie, celle ci s'arrete.
** -
** ARGUMENTS:
** -
** [void *dest]:
** un pointeur sur la zone memoire dans laquelle copier.
** [const void *src]:
** un pointeur sur la zone memoire a copier.
** [int c]:
** le caractere arretant la copie si trouvé.
** [size_t n]:
** le nombre d'octet a copier.
** -
** RETOUR:
** -
** [void *]:
** ft_memccpy renvoie NULL si le caractere c n'a pas ete rencontré, sinon
** renvoie un pointeur sur l'octet suivant celui contenant la copie de c
** dest.
** -
*/
