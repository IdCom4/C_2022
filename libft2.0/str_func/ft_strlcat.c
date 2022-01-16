/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:55:57 by idcornua          #+#    #+#             */
/*   Updated: 2019/01/17 11:09:21 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcat(char *dest, const char *src, size_t size) {

  size_t dLen = ft_strlen(dest);

  if (size <= dLen || !src)
    return ft_strlen(src) + size;
  
  size_t i;
  
  for (i = 0; dLen + i < size - 1 && src[i] != '\0'; i++)
    dest[dLen + i] = src[i];
  
  dest[dLen + i] = '\0';
  return ft_strlen(src) + dLen;
}
