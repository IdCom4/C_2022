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

char	*ft_realloc(char *str, size_t new_size)
{
	char	*tmp;

	if (!str || !(tmp = ft_strnew(new_size)))
		return (NULL);
	ft_strcpy(tmp, str);
	free(str);
	return (tmp);
}
