/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lllen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:09:27 by idcornua          #+#    #+#             */
/*   Updated: 2019/01/24 19:03:29 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lllen(long long n, int no_sign) {
	int									len = (n < 0) ? 2 : 1;
	unsigned long long	nb = (!no_sign && n < 0) ? -n : n;

	while (nb >= 10) {
		len++;
		nb /= 10;
	}

	return (len);
}

/*
** === MAN ft_intlen ===
** -
** DESCRIPTION:
** -
** ft_intlen compte le nombre de caracteres necessaires pour contenir l'int n.
** -
** ARGUMENTS:
** -
** [int n]:
** un int dont on veut connaitre la longueur en terme de caracteres.
** -
** RETOUR:
** -
** [int]
** ft_intlen renvoie un int indiquant le nombre de caracteres necessaires pour
** contenir l'int n.
** -
*/
