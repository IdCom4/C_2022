/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:03:19 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/13 15:04:37 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

/*
** === MAN ft_putstr_fd ===
** -
** DESCRIPTION:
** -
** ft_putstr_fd affiche sur la sortie standard la chaine de caractere s.
** -
** ARGUMENTS:
** -
** [char const *s]:
** la chaine caractere a afficher.
** [int fd]:
** le file descriptor sur lequel afficher.
** -
** RETOUR:
** -
** [void]
** -
*/
