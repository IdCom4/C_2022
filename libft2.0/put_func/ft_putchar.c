/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:57:27 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/12 14:58:22 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
** === MAN ft_putchar ===
** -
** DESCRIPTION:
** -
** ft_putchar affiche sur la sortie standard le caractere c.
** -
** ARGUMENTS:
** -
** [char c]:
** le caractere a afficher.
** -
** RETOUR:
** -
** [void]
** -
*/
