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

char	*ft_strnjoinf(char const *s1, char const *s2, size_t size, int toFree) {
	char    *join;
	int     i = 0;
	size_t	n = 0;

	if (!s1 || !s2 || !(join = malloc(sizeof(char) * (ft_strlen(s1) + size + 1))))
		return (NULL);
  
	while (s1[n] != '\0')
		join[i++] = s1[n++];

	n = 0;
	while (s2[n] != '\0' && n < size)
		join[i++] = s2[n++];

	join[i] = '\0';

	if (toFree == FIRST || toFree == SECOND)
		free((toFree == FIRST) ? (char *)s1 : (char *)s2);
	else {
		free((char *)s1);
		free((char *)s2);
	}

	return (join);
}
