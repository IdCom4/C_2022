/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:53:38 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/13 15:01:12 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n) {

	// if n is negative, print its sign
	if (n < 0)
		ft_putchar('-');
	
	// then anyway make it positive
	unsigned int  nb = (n < 0) ? -n : n;

	// then print it recursively
	if (nb >= 10) {
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

/*
** === MAN ft_putnbr ===
** -
** DESCRIPTION:
** -
** ft_putnbr affiche sur la sortie standard l'int n.
** -
** ARGUMENTS:
** -
** [int n]:
** l'int a afficher.
** -
** RETOUR:
** -
** [void]
** -
*/
