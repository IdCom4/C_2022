/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:33:41 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/09 11:40:14 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[n] != '\0')
	{
		dest[i] = src[n];
		i++;
		n++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
** === MAN ft_strcat ===
** -
** DESCRIPTION:
** -
** ft_strcat copie la chaine de caracteres src a la fin de celle de dest,
** octet NULL final compris, en partant du principe qu'elle a assez de memoire
** allouee.
** -
** ARGUMENTS:
** -
** [char *dest]:
** la chaine caractere a la fin de laquelle copier.
** [char const *s]:
** la chaine caractere a copier.
** -
** RETOUR:
** -
** [char *]:
** ft_strcat renvoie dest.
** -
*/
