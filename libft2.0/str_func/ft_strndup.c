/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:53:34 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/06 17:14:44 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *toDup, size_t n)
{
	char	*dup;

	if (!(dup = ft_strnew(n)))
		return (NULL);

	ft_strncpy(dup, toDup, n);

	return (dup);
}
