/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:51:22 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/09 15:56:24 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int						i;
	const unsigned char		*s1b;
	const unsigned char		*s2b;

	i = 0;
	s1b = (const unsigned char *)s1;
	s2b = (const unsigned char *)s2;
	while (s1b[i] == s2b[i] && s1b[i] != '\0')
	{
		i++;
	}
	return (s1b[i] - s2b[i]);
}

/*
** === MAN ft_strcmp ===
** -
** DESCRIPTION:
** -
** ft_strcmp compare chaque caractere des chaines s1 et s2.
** -
** ARGUMENTS:
** -
** [const char *s1]:
** la premiere chaine de caracteres a comparer.
** [const char *s2]:
** la deuxieme chaine de caracteres a comparer.
** -
** RETOUR:
** -
** [int]:
** ft_strcmp renvoie 0 si les chaines sont identiques, sinon la valeur de la
** soustraction des deux caracteres differents.
** -
*/
