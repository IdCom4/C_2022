/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:30:23 by idcornua          #+#    #+#             */
/*   Updated: 2019/06/25 11:00:09 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i = 0;
	char			*s2;

	if (!s)
    return (NULL);
	if (!(s2 = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);

	while (s[i] != '\0') {
		s2[i] = (*f)(i, s[i]);
		i++;
	}

	s2[i] = '\0';
	return (s2);
}
