/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:27:42 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/06 16:21:01 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, const unsigned char c)
{
  if (!s)
		return (NULL);
  if (c == '\0')
    return (char *)&s[ft_strlen(s)];

	for (size_t i = 0; s[i] != '\0'; i++)
		if (s[i] == c) return (char *)&s[i];

	return NULL;
}

/*
** === MAN ft_strchr ===
** -
** DESCRIPTION:
** -
** ft_strchr parcours la chaine de caracteres s a la recherche du caractere c.
** -
** ARGUMENTS:
** -
** [const char *s]:
** la chaine de caracteres dans laquelle chercher.
** [const unsigned char c]:
** le caractere a chercher.
** -
** RETOUR:
** -
** [char *]:
** ft_strchr renvoie un pointeur sur l'octet contenant c dans s s'il existe,
** sinon elle renvoie NULL.
** -
*/
