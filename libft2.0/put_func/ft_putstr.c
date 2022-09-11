/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:56:13 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/12 14:59:08 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s) {
	write(1, s, ft_strlen(s));
}

/*
** === MAN ft_putstr ===
** -
** DESCRIPTION:
** -
** ft_putstr affiche sur la sortie standard la chaine de caractere s.
** -
** ARGUMENTS:
** -
** [char const *s]:
** la chaine caractere a afficher.
** -
** RETOUR:
** -
** [void]
** -
*/
