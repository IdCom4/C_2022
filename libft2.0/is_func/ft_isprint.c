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

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
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
** [int c]:
** un int representant le caractere ASCII a tester.
** -
** RETOUR:
** -
** [int]
** ft_isprint retourne 1 si le caractere est affichable, 0 sinon.
** -
*/
