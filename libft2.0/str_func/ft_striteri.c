/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:30:23 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/12 11:48:37 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	if (!s || !f)
		return ;

	for (size_t i = 0; s[i] != '\0'; i++)
		(*f)(i, &s[i]);
}

/*
** === MAN ft_striteri ===
** -
** DESCRIPTION:
** -
** ft_striteri applique la fonction f a chaque caractere de la chaine s,
** en prenant en compte l'index de chaque caractere.
** -
** ARGUMENTS:
** -
** [char *s]:
** la chaine de caracteres sur laquelle appliquer f.
** [void (*f)(unsigned int, char *)]:
** la fonction a appliquer sur les caracteres de s.
** -
** RETOUR:
** -
** [void]
** -
*/
