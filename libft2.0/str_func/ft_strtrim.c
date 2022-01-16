/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:23:37 by idcornua          #+#    #+#             */
/*   Updated: 2019/06/25 11:03:21 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  ft_is_blank_char(char c) {
  return ((c == ' ' || c == '\n' || c == '\t'));
}

char        *ft_strtrim(char const *s)
{
	if (!s)
		return (NULL);

  char	*trim;
  size_t sLen = ft_strlen(s);
  size_t start;
	size_t end;

  for (start = 0; s[start] != '\0' && ft_is_blank_char(s[start]); start++);
  for (end = sLen - 1; end >= 0 && ft_is_blank_char(s[end]); end--);

  end++;

	if (end <= start || !(trim = (char *)malloc(sizeof(char) * ((end - start)) + 1)))
		return (NULL);

  for (size_t i = 0; i + start < end; i++)
    trim[i] = s[start + i];

	trim[end - start] = '\0';
	return (trim);
}
