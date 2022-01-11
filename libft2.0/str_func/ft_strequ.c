/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:54:49 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/12 11:59:18 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	if (s1[i] == s2[i])
		return (1);
	return (0);
}

/*
** === MAN ft_strequ ===
** -
** DESCRIPTION:
** -
** ft_strequ compare les deux chaines de caracteres s1 et s2.
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
** ft_strequ renvoie 1 si les chaines sont egales, 0 sinon.
** -
*/
