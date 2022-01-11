/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:16:43 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/12 11:42:36 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfill(char *str, char c, size_t n)
{
	size_t i;

	i = 0;
	if (!str)
		return (NULL);
	while (i < n)
		str[i++] = c;
	str[i] = 0;
	return (str);
}
