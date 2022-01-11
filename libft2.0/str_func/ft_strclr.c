/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:27:39 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/12 13:13:27 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	if (s)
		ft_bzero(s, ft_strlen(s));
}

/*
** === MAN ft_strclr ===
** -
** DESCRIPTION:
** -
** ft_strclr parcours la chaine de caracteres s en mettant chacun de ses
** octets a 0.
** -
** ARGUMENTS:
** -
** [char *s]:
** la chaine de caracteres a set.
** -
** RETOUR:
** -
** [void]
** -
*/
