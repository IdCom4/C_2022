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

char	*ft_strcjoinf(char const *s1, char const *s2, char c, int toFree)
{
  if (!s1 || !s2)
		return (NULL);

	char	*join;
  size_t s1Len = ft_strlen(s1);
	long joinEndIndex = ft_strichr((char *)s2, c);

  if (joinEndIndex < 0)
	  joinEndIndex = ft_strlen(s2);

	if (!(join = ft_strnew(s1Len + joinEndIndex)))
		return NULL;
  
	for (size_t j = 0; j < s1Len; j++)
		join[j] = s1[j];

  for (size_t j = 0; s2[j] != '\0' && s2[j] != c; j++)
		join[s1Len + j] = s2[j];

  join[s1Len + joinEndIndex] = '\0';
  
	if (toFree == FIRST || toFree == SECOND)
		free((toFree == 0) ? (char *)s1 : (char *)s2);
	else {
    free((char *)s1);
    free((char *)s2);
  }
		
	return join;
}
