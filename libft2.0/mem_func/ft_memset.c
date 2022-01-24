/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:46:16 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/08 14:09:38 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *s2 = s;

	while (n > 0) {
		*s2 = c;
		s2++;
		n--;
	}

	return (s);
}

/*
** === MAN ft_memset ===
** -
** DESCRIPTION:
** -
** ft_memset donne aux n premiers octets de s la valeur de c.
** -
** ARGUMENTS:
** -
** [void *s]:
** un pointeur sur la zone memoire a set.
** [int c]:
** la valeur a donner aux n premiers octets de s.
** [size_t n]:
** le nombre d'octet a set.
** -
** RETOUR:
** -
** [void *]:
** ft_memset renvoie s.
** -
*/
