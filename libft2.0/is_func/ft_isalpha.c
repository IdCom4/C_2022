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

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
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
** [int c]:
** un int representant le caractere ASCII a tester.
** -
** RETOUR:
** -
** [int]
** ft_isalpha retourne 1 si le caractere est alphabetique, 0 sinon.
** -
*/
