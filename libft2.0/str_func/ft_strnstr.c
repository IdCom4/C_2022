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

char	*ft_strnstr(const char *toFindIn, const char *toFind, size_t len)
{
	unsigned long i = 0;
	unsigned long n;

	if (ft_strlen(toFind) == 0)
		return ((char *)(toFindIn));

	while (toFindIn[i] != '\0' && i < len)
	{
		n = 0;
		while (toFindIn[i + n] == toFind[n] && toFindIn[i + n] != '\0' && i + n < len)
			n++;

		if (toFind[n] == '\0')
			return ((char *)(&toFindIn[i]));
		i++;
	}

	return (NULL);
}
