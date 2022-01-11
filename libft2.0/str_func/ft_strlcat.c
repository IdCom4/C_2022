/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:55:57 by idcornua          #+#    #+#             */
/*   Updated: 2019/01/17 11:09:21 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned long i;
	unsigned long n;
	unsigned long len_dest;

	n = 0;
	len_dest = ft_strlen(dest);
	i = len_dest;
	if (size <= len_dest)
		return (ft_strlen(src) + size);
	while (i < size - 1 && src[n] != '\0')
	{
		dest[i] = src[n];
		n++;
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src) + len_dest);
}
