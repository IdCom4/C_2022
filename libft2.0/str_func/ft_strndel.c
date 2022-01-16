/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:51:55 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/06 17:16:03 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndel(char *s, int deleteSide, size_t indexToRemoveFrom) {
	if (!s)
    return NULL;
  
  char	  *temp;
  size_t  sLen = ft_strlen(s);

	if (sLen < indexToRemoveFrom)
		return NULL;

	if (deleteSide == START)
		temp = ft_strdup(&s[indexToRemoveFrom]);
  else
    temp = ft_strndup(s, sLen - indexToRemoveFrom);

  ft_strdel(&s);
  return temp;
}
