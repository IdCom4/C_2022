/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:15:31 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/09 15:36:25 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (!needle)
		return ((char *)(haystack));

	for (unsigned long i = 0; haystack[i] != '\0'; i++) {

    unsigned long n;
		for (n = 0; haystack[i + n] == needle[n] && haystack[i + n] != '\0'; n++);

		if (needle[n] == '\0')
			return ((char *)(&haystack[i]));

	}

	return (NULL);
}
