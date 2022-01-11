/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:30:23 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/12 11:38:20 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(&s[i]);
		i++;
	}
}

/*
** === MAN ft_striter ===
** -
** DESCRIPTION:
** -
** ft_striter applique la fonction f a chaque caractere de la chaine s.
** -
** ARGUMENTS:
** -
** [char *s]:
** la chaine de caracteres sur laquelle appliquer f.
** [void (*f)(char *)]:
** la fonction a appliquer sur les caracteres de s.
** -
** RETOUR:
** -
** [void]
** -
*/
