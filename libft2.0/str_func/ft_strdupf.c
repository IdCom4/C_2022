/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:10:45 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/08 11:13:23 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupf(char *toDup, char *toFree)
{
	if (!toDup)
		return (NULL);

	if (toFree)
		free(toFree);

	return (ft_strdup(toDup));
}
