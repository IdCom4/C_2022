/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:26:59 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/09 16:53:09 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
** === MAN ft_isascii ===
** -
** DESCRIPTION:
** -
** ft_isascii regarde si l'int c rentre dans les index de la table ASCII.
** -
** ARGUMENTS:
** -
** [int c]:
** un int representant l'index a tester.
** -
** RETOUR:
** -
** [int]
** ft_isascii retourne 1 si c  est uun caractere ASCII, 0 sinon.
** -
*/
