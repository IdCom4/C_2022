/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:26:08 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/05 15:43:58 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *s2;

	s2 = s;
	while (n > 0)
	{
		if (*s2 == (unsigned char)c)
			return ((void *)(s2));
		s2++;
		n--;
	}
	return (NULL);
}

/*
** === MAN ft_memchr ===
** -
** DESCRIPTION:
** -
** ft_memchr recherche le caractere c dans les n premiers octets de la zone
** memoire pointee par s.
** -
** ARGUMENTS:
** -
** [const void *s]:
** un pointeur sur la zone memoire a fouiller.
** -
** RETOUR:
** -
** [void *]:
** ft_memchr renvoie un pointeur sur l'octet contenant c dans s s'il a ete
** trouvé, NULL sinon.
** -
*/
