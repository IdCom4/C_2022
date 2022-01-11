/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:08:50 by idcornua          #+#    #+#             */
/*   Updated: 2019/06/25 10:59:26 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char const *s1, char const *s2, int to_free)
{
	char	*join;
	int		i;
	int		n;

	if (!s1 || !s2)
		return (NULL);
	if (!(join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	n = 0;
	while (s1[n] != '\0')
		join[i++] = s1[n++];
	n = 0;
	while (s2[n] != '\0')
		join[i++] = s2[n++];
	join[i] = '\0';
	if (to_free == 0 || to_free == 1)
		free((to_free == 0) ? (char *)s1 : (char *)s2);
	else
	{
		free((char *)s1);
		free((char *)s2);
	}
	return (join);
}
