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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned long		i;
	unsigned char		*dest2;
	const unsigned char	*src2;

	dest2 = dest;
	src2 = src;
	i = 0;
	if (dest2 <= src2)
	{
		while (i < n)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	else
	{
		while (n != 0)
		{
			dest2[n - 1] = src2[n - 1];
			n--;
		}
	}
	return (dest);
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
