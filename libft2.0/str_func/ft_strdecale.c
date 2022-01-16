/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:08:09 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/13 11:24:07 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strshift(char *str, int shiftFromIndex, int shiftTo, size_t len)
{
	if (!str)
		return (NULL);

  size_t i;
	len = ((len < 0) ? ft_strlen(str) : len) - 1;

	if (shiftTo == START) {
		for (i = 0; str[i + shiftFromIndex] != '\0'; i++)
			str[i] = str[i + shiftFromIndex];

    str[i] = 0;
	}
  else {
		while (len - shiftFromIndex >= 0) {
			str[len] = str[len - shiftFromIndex];
			len--;
		}
	}

	return (str);
}
