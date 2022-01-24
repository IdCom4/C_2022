/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:37:40 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/10 16:16:12 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1c = s1;
	const unsigned char	*s2c = s2;
	int					val;

	while (n > 0)
	{
		val = *s1c - *s2c;
		if (val)
			return (val);
		s1c++;
		s2c++;
		n--;
	}
	return (0);
}

/*
** === MAN ft_memcmp ===
** -
** DESCRIPTION:
** -
** ft_memcmp soustrait octet par octet ceux de s2 a ceux s1, jusqu'a n octets.
** Si une soustraction n'est pas egale a 0, la comparaison s'arrete.
** -
** ARGUMENTS:
** -
** [const void *s1]:
** un pointeur sur la premiere zone memoire a comparer.
** [const void *s2]:
** un pointeur sur la deuxieme zone memoire a comparer.
** [size_t n]:
** le nombre d'octet a comparer.
** -
** RETOUR:
** -
** [int]:
** ft_memcmp renvoie 0 si les n premiers octets des deux zones memoires sont
** identiques, sinon la valeur de la soustraction des deux octets differents.
** -
*/
