/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:26:59 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/09 16:37:05 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/*
** === MAN ft_isalnum ===
** -
** DESCRIPTION:
** -
** ft_isalnum regarde si le caractere ASCII c est alphanumerique.
** -
** ARGUMENTS:
** -
** [int c]:
** un int representant le caractere ASCII a tester.
** -
** RETOUR:
** -
** [int]
** ft_isalnum retourne 1 si le caractere est alphanumerique, 0 sinon.
** -
*/
