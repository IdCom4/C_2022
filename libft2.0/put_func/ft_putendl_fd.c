/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:05:05 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/13 15:07:04 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*
** === MAN ft_putendl_fd ===
** -
** DESCRIPTION:
** -
** ft_putendl_fd affiche la chaine de caracteres s suivie d'un retour a la
** ligne sur le file descriptor fd.
** -
** ARGUMENTS:
** -
** [char const *s]:
** la chaine de caracteres a afficher.
** [int fd]:
** le file descriptor sur lequel afficher.
** -
** RETOUR:
** -
** [void]
** -
*/
