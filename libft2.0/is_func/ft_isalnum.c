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

t_bool	ft_isalnum(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (TRUE);
	return (FALSE);
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
** [char c]:
** un char representant le caractere ASCII a tester.
** -
** RETOUR:
** -
** [t_bool]
** ft_isalnum retourne TRUE si le caractere est alphanumerique, FALSE sinon.
** -
*/
