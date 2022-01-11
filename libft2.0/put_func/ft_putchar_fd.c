/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:01:33 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/13 15:03:02 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
** === MAN ft_putchar_fd ===
** -
** DESCRIPTION:
** -
** ft_putchar_fd affiche sur le file descriptor fd le caractere c.
** -
** ARGUMENTS:
** -
** [char c]:
** le caractere a afficher.
** [int fd]:
** le file descriptor sur lequel afficher.
** -
** RETOUR:
** -
** [void]
** -
*/
