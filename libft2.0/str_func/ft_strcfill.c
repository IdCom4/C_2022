/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:18:48 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/13 14:07:08 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcfill(char *dest, char *src, const unsigned char c, size_t len)
{
  if (!dest || !src)
		return NULL;

	for (size_t i = 0; i < len && dest[i] && src[i]; i++)
		dest[i] = (dest[i] == c) ? src[i] : dest[i];

	return dest;
}
