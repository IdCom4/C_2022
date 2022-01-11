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
	int i;
	int n;

	i = 0;
	if (ft_strlen(needle) == 0)
		return (-1);
	while (haystack[i] != '\0')
	{
		n = 0;
		while (haystack[i + n] == needle[n] && haystack[i + n] != '\0')
			n++;
		if (needle[n] == '\0' && n > 0)
			return (i);
		i++;
	}
	return (-1);
}
