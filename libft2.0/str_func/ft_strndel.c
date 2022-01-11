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

char	*ft_strndel(char *s, int deleteFrom, size_t to_remove) {
	char	*temp;
  int   sLen = ft_strlen(s);

	if (sLen == 0)
		return (NULL);
	if (sLen < to_remove)
		return (NULL);

	if (deleteFrom == START)
		temp = ft_strdup(&s[to_remove]);
  else
    temp = ft_strndup(s, sLen - to_remove);

  ft_strdel(&s);
  return (temp);
}
