/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:11:14 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/09 15:15:11 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
  int lastOccIndex = -1;
	int i = 0;

	while (s[i] != '\0') {
		if (s[i] == c)
      lastOccIndex = i;
		i++;
	}

	return ((lastOccIndex >= 0 ? (char *)(&s[lastOccIndex]) : NULL));
}
