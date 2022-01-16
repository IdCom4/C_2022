/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:27:42 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/06 16:22:42 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strichr(const char *s, const unsigned char c)
{
  if (c == '\0')
    return !s ? 0 : ft_strlen(s);

	for (size_t i = 0; s[i] != '\0'; i++)
		if (s[i] == c) return (i);

	return (-1);
}

/*
** === MAN ft_strichr ===
** -
** DESCRIPTION:
** -
** ft_strichr parcours une chaine de caracteres jusqu'a trouver le caractere
** c ou l'octet nul de fin.
** -
** ARGUMENTS:
** -
** [const char *s]:
** un pointeur sur le debut de la chaine de caracteres.
** [unsigned char c]:
** le caractere a trouver dans la chaine pointee par s.
** -
** RETOUR:
** -
** [int]:
** ft_strichr renvoie l'index auquel il a trouvé c dans s, ou -1 s'il ne l'a
** pas trouvé.
** -
*/
