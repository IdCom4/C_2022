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

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(&s[i]));
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)(&s[i]));
	return (NULL);
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
** [int c]:
** le caractere a chercher.
** -
** RETOUR:
** -
** [char *]:
** ft_strchr renvoie un pointeur sur l'octet contenant c dans s s'il existe,
** sinon elle renvoie NULL.
** -
*/
