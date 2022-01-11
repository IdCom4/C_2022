/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:09:27 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/21 15:16:37 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int				len;
	unsigned int	nb;

	len = (n < 0) ? 2 : 1;
	nb = (n < 0) ? -n : n;
	while (nb >= 10)
	{
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
