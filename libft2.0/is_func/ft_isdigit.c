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

t_bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
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
** [char c]:
** un char representant le caractere ASCII a tester.
** -
** RETOUR:
** -
** [t_bool]
** ft_isdigit retourne TRUE si le caractere est un chiffre, FALSE sinon.
** -
*/
