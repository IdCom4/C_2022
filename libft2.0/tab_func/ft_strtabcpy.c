/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:50:43 by idcornua          #+#    #+#             */
/*   Updated: 2019/07/12 14:40:20 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtabcpy(char **dest, char **src, size_t src_size) {
	for (size_t i = 0; i < src_size; i++)
	  ft_strcpy(dest[i], (const char *)src[i]);
}

/*
** === MAN ft_strtabcpy ===
** -
** DESCRIPTION:
** -
** ft_strtabcpy copies the content of a str tab to another one.
** dest and its strings must be allocated to receive src's content.
** It doesn't free src.
** -
** ARGUMENTS:
** -
** [char **dest]:
** The string array inside which to copy the source.
** [char **src]:
** The string array of which string to copy.
** [size_t src_size]:
** The length of src.
** -
** RETURN:
** -
** [void]
** -
*/
