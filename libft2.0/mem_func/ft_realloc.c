/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:39:53 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/14 12:28:43 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, size_t newSize)
{
	char	*newStr;

	if (!str || !(newStr = ft_strnew(newSize)))
		return (NULL);
	
	ft_strcpy(newStr, str);
	free(str);
	return (newStr);
}
