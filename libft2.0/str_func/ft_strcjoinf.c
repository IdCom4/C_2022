/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoinf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:08:50 by idcornua          #+#    #+#             */
/*   Updated: 2019/06/25 10:56:18 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoinf(char const *s1, char const *s2, char c, int to_free)
{
	char	*join;
	int		i;
	int		n;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strichr((char *)s2, c);
	i = (i < 0) ? ft_strlen(s2) : i;
	if (!(join = ft_strnew(ft_strlen(s1) + i)))
		return (NULL);
	i = 0;
	n = 0;
	while (s1[n] != '\0')
		join[i++] = s1[n++];
	n = 0;
	while (s2[n] != '\0' && s2[n] != c)
		join[i++] = s2[n++];
	if (to_free == 0 || to_free == 1)
		free((to_free == 0) ? (char *)s1 : (char *)s2);
	if (to_free >= 2)
		free((char *)s1);
	if (to_free >= 2)
		free((char *)s2);
	return (join);
}
