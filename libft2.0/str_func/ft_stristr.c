/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stristr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:15:31 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/09 15:36:25 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stristr(const char *haystack, const char *needle)
{
	if (!needle)
		return (-1);

	for (size_t i = 0; haystack[i] != '\0'; i++) {
		
    size_t n;
    for (n = 0; haystack[i + n] == needle[n] && haystack[i + n] != '\0'; n++);

		if (needle[n] == '\0' && n > 0)
			return (i);
	}
	return (-1);
}
