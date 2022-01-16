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
  size_t i = ft_strlen(dest);

	for (size_t j = 0; src[j] != '\0'; j++)
		dest[i++] = src[j];

	dest[i] = '\0';
	return dest;
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
