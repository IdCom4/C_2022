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

char	*ft_strcfill(char *dest, char *src, char c, int size)
{
	int i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (i < size && dest[i] && src[i])
	{
		dest[i] = (dest[i] == c) ? src[i] : dest[i];
		i++;
	}
	return (dest);
}
