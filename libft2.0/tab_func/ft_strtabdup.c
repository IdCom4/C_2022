/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:28:57 by idcornua          #+#    #+#             */
/*   Updated: 2019/07/12 13:49:37 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabdup(char **tab, size_t tab_size)
{
	char	**dup;

	if (tab_size == 0 || !tab || !(dup = (char **)ft_mallstrtab(tab_size, 0)))
		return (NULL);

	for (size_t n = 0; n < tab_size; n++) {
		if (!(dup[n] = ft_strdup(tab[n])))
			return (ft_freestrtabn(dup, n, TRUE));
	}

  dup[tab_size] = 0;
	return (dup);
}
