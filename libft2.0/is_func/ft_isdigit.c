/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:26:59 by idcornua          #+#    #+#             */
/*   Updated: 2019/04/11 15:36:08 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
** === MAN ft_isdigit ===
** -
** DESCRIPTION:
** -
** ft_isdigit regarde si le caractere ASCII c est un chiffre.
** -
** ARGUMENTS:
** -
** [int c]:
** un int representant le caractere ASCII a tester.
** -
** RETOUR:
** -
** [int]
** ft_isdigit retourne 1 si le caractere est un chiffre, 0 sinon.
** -
*/
