/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:26:59 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/09 16:32:37 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isalpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (TRUE);
	return (FALSE);
}

/*
** === MAN ft_isalpha ===
** -
** DESCRIPTION:
** -
** ft_isalpha regarde si le caractere ASCII c est alphabetique.
** -
** ARGUMENTS:
** -
** [char c]:
** un char representant le caractere ASCII a tester.
** -
** RETOUR:
** -
** [t_bool]
** ft_isalpha retourne TRUE si le caractere est alphabetique, FALSE sinon.
** -
*/
