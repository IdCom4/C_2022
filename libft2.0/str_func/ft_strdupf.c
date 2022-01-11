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

char	*ft_strdupf(char *to_dup, char *to_free)
{
	if (!to_dup)
		return (NULL);
	if (to_free)
		free(to_free);
	return (ft_strdup(to_dup));
}
