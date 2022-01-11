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

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	unsigned long y = 0;
	unsigned long i = ft_strlen(dest);
  
	while (y < n && src[y] != '\0')
		dest[i++] = src[y++];

	dest[i] = '\0';
	return (dest);
}
