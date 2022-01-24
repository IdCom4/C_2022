/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:08:50 by idcornua          #+#    #+#             */
/*   Updated: 2019/06/25 11:01:32 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoinf(char const *s1, char const *s2, size_t n, int toFree) {
  if (!s1 || !s2)
    return NULL;

	char    *join;

	if (!(join = malloc(sizeof(char) * (ft_strlen(s1) + n + 1))))
		return (NULL);
  
	size_t i = 0;
	for (size_t j = 0; s1[j] != '\0';)
		join[i++] = s1[j];

	for (size_t j = 0; j < n && s2[j] != '\0';)
		join[i++] = s2[j];

	join[i] = '\0';

	if (toFree == FIRST || toFree == SECOND)
		free((toFree == FIRST) ? (char *)s1 : (char *)s2);
	else {
		free((char *)s1);
		free((char *)s2);
	}

	return (join);
}
