/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocstrtab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:49:59 by idcornua          #+#    #+#             */
/*   Updated: 2019/07/12 14:46:20 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_reallocstrtab(char **tab, size_t old_size, size_t new_size) {
	
	char	**new = NULL;

	// if new_size is NULL or mem alloc fail, return NULL
	if (!new_size || !(new = ft_mallstrtab(new_size, 0)))
		return (NULL);

	// if there is no tab to transfer or that it's empty, just return the new one
	if (!tab || old_size == 0)
		return (new);

	// transfer content from old to new tab
	for (size_t i = 0; i < old_size; i++)
		new[i] = tab[i];

	// free the old one
	free(tab);

	// return the new one
	return (new);
}
