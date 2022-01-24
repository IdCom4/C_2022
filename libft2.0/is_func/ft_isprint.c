/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:26:59 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/09 17:02:52 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isprint(char c)
{
	if (c >= 32 && c <= 126)
		return (TRUE);
	return (FALSE);
}

/*
** === MAN ft_isprint ===
** -
** DESCRIPTION:
** -
** ft_isprint regarde si le caractere ASCII c est affichable.
** -
** ARGUMENTS:
** -
** [char c]:
** un char representant le caractere ASCII a tester.
** -
** RETOUR:
** -
** [t_bool]
** ft_isprint retourne TRUE si le caractere est affichable, FALSE sinon.
** -
*/
