/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:16:47 by idcornua          #+#    #+#             */
/*   Updated: 2019/06/25 11:00:52 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewclean(size_t size)
{
	char *new;

	if ((new = (char *)malloc(sizeof(char) * (size + 1))))
		ft_bzero(new, size + 1);

	return (new);
}

/*
** === MAN ft_strnewclean ===
** -
** DESCRIPTION:
** -
** ft_strnewclean create a new char pointer and allocate it the amount of memory
** specified by size.
** -
** ARGUMENTS:
** -
** [size_t size]:
** the amount of memory to allocate
** -
** RETURN:
** -
** [char *]
** the newly created and allocated char pointer
** -
*/
