/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcharsjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:08:50 by idcornua          #+#    #+#             */
/*   Updated: 2019/06/25 10:56:18 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcharsjoinf(char const *s1, char const *s2, char *chars, int *charFoundIndex)
{
  if (!s1 || !s2)
		return (NULL);

  char *join;
  size_t s1Len = ft_strlen(s1);
	size_t s2ToJoinLen;
	*charFoundIndex = -1;

	for (s2ToJoinLen = 0; s2[s2ToJoinLen] != '\0' && ft_strichr(chars, s2[s2ToJoinLen]) < 0; s2ToJoinLen++);

	if (s2[s2ToJoinLen] != '\0') *charFoundIndex = s2ToJoinLen;

  if (s2ToJoinLen < 0)
	  s2ToJoinLen = ft_strlen(s2);

	if (!(join = ft_strnew(s1Len + s2ToJoinLen)))
		return NULL;
  
	for (size_t j = 0; j < s1Len; j++)
		join[j] = s1[j];

  for (size_t j = 0; j < s2ToJoinLen; j++)
		join[s1Len + j] = s2[j];

  join[s1Len + s2ToJoinLen] = '\0';
		
	return join;
}
