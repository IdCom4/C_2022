/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:40:27 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/09 11:52:27 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n) {
  if (!src || n <= 0)
    return dest;

	size_t dLen = ft_strlen(dest);
  size_t i;

  for (i = 0; i < n && src[i] != '\0'; i++)
    dest[dLen + i] = src[i];

	dest[i] = '\0';
	return (dest);
}
