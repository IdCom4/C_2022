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

int	ft_strcmp(const unsigned char *s1, const unsigned char *s2)
{
	size_t i = 0;

	for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++);

	return (s1[i] - s2[i]);
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
