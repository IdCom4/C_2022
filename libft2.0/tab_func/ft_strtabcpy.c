/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:50:43 by idcornua          #+#    #+#             */
/*   Updated: 2019/07/12 14:40:20 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtabcpy(char **dest, char **src, size_t src_size)
{
	for (size_t i = 0; i < src_size; i++)
	  ft_strcpy(dest[i], (const char *)src[i]);
}
