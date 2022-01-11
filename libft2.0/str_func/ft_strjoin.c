/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:08:50 by idcornua          #+#    #+#             */
/*   Updated: 2019/06/25 10:57:20 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		n;

	if (!s1 || !s2)
		return (NULL);
	if (!(join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	n = 0;
	while (s1[n] != '\0')
	{
		join[i] = s1[n];
		i++;
		n++;
	}
	n = 0;
	while (s2[n] != '\0')
	{
		join[i] = s2[n];
		i++;
		n++;
	}
	join[i] = '\0';
	return (join);
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
