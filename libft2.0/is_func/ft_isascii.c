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

t_bool	ft_isascii(char c)
{
	if (c >= 0 && c <= 127)
		return (TRUE);
	return (FALSE);
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
** [char c]:
** un char representant l'index a tester.
** -
** RETOUR:
** -
** [t_bool]
** ft_isascii retourne TRUE si c est un caractere ASCII, FALSE sinon.
** -
*/
