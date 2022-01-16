/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:36:50 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/09 15:51:10 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!needle)
		return ((char *)(haystack));

	for (unsigned long i = 0; haystack[i] != '\0' && i < len; i++) {
		
    unsigned long n;
		for (n = 0; haystack[i + n] == needle[n] && haystack[i + n] != '\0' && i + n < len; n++);

		if (needle[n] == '\0')
			return ((char *)(&haystack[i]));

	}

	return (NULL);
}
