/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:18:50 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/13 12:24:52 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src) {
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';
	
	return (dest);
}

/*
** === MAN ft_strcpy ===
** -
** DESCRIPTION:
** -
** ft_strcpy copie la chaine de caracteres src dans celle de dest, en partant
** du principequ'elle a assez de memoire allouee.
** -
** ARGUMENTS:
** -
** [char *dest]:
** la chaine de caracteres dans laquelle copier.
** [const char *src]:
** la chaine de caracteres a copier.
** -
** RETOUR:
** -
** [char *]:
** ft_strcpy renvoie dest.
** -
*/
