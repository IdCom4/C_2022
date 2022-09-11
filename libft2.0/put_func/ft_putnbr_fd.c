/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:53:38 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/13 15:08:58 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd) {

	if (n < 0)
		ft_putchar_fd('-', fd);

	unsigned int nb = (n < 0) ? -n : n;
	if (nb >= 10) {
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + 48, fd);
}

/*
** === MAN ft_putnbr_fd ===
** -
** DESCRIPTION:
** -
** ft_putnbr_fd affiche sur le file descriptor fd l'int n.
** -
** ARGUMENTS:
** -
** [int n]:
** l'int a afficher.
** [int fd]:
** le file descriptor sur lequel afficher.
** -
** RETOUR:
** -
** [void]
** -
*/
