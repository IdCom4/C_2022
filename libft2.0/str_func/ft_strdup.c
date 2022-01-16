/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:53:34 by idcornua          #+#    #+#             */
/*   Updated: 2019/01/25 17:34:39 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *toDup)
{
  if (!toDup)
		return (NULL);

	char	*dup;
	if (!(dup = ft_strnew(ft_strlen(toDup))))
		return NULL;

	ft_strcpy(dup, toDup);
	return (dup);
}

/*
** === MAN ft_strdup ===
** -
** DESCRIPTION:
** -
** ft_strdup cree une copie de la chaine de caracteres s.
** -
** ARGUMENTS:
** -
** [const char *s]:
** la chaine de caracteres a copier.
** -
** RETOUR:
** -
** [char *]:
** ft_strdup renvoie la copie de s si l'allocation a fonctionnee, NULL sinon.
** -
*/
