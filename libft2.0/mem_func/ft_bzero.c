/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:16:24 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/24 14:32:09 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *s2 = s;

	while (n > 0)
		s2[--n] = 0;
}

/*
** === MAN ft_bzero ===
** -
** DESCRIPTION:
** -
** ft_bzero fill the memory location pointed by s with 0.
** -
** ARGUMENTS:
** -
** [void *s]:
** the pointer to the memory zone to zero fill.
** [size_t n]:
** the length of the memory space to zero fill.
** -
** RETURN:
** -
** [void]
** -
*/
