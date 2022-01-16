/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:08:50 by idcornua          #+#    #+#             */
/*   Updated: 2019/06/25 10:57:20 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	if (!(join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
  
  size_t i = 0;
  for (size_t j = 0; s1[j] != '\0'; j++)
		join[i++] = s1[j];

  for (size_t j = 0; s2[j] != '\0'; j++)
		join[i++] = s2[j];

	join[i] = '\0';
	return (join);
}
