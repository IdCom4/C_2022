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

int		ft_strcharschr(const char *s, const char *chars)
{
	for (size_t i = 0; s[i] != '\0'; i++)
		if (ft_strichr(chars, s[i]) >= 0) return (i);

	return (-1);
}

/*
** === MAN ft_strcharschr ===
** -
** DESCRIPTION:
** -
** ft_strichr parcours une chaine de caracteres jusqu'a trouver l'un des caracteres
** contenu dans la string chars ou l'octet nul de fin.
** -
** ARGUMENTS:
** -
** [const char *s]:
** un pointeur sur le debut de la chaine de caracteres.
** [const char *chars]:
** une string contenant tous les caractères recherchés.
** -
** RETOUR:
** -
** [int]:
** ft_strichr renvoie l'index auquel il a trouvé l'un des chars dans s, ou -1 s'il n'en a
** pas trouvé.
** -
*/
