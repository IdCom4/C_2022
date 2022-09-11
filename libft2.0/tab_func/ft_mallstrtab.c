/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallstrtab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:12:02 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/11 10:59:51 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_mallstrtab(size_t tab_size, const size_t str_size) {
	
	char		**tab = NULL;
	// mem alloc tab, and return NULL if failure
	if (!(tab = (char **)malloc(sizeof(char *) * tab_size)))
		return (NULL);

	// for each tab entry
	for (size_t i = 0; i < tab_size; i++) {
		// if an str_size is specified alloc it
		if (str_size) {
			// if failure free what's allocated & return NULL
			if (!(tab[i] = ft_strnew(str_size))) {
				ft_freestrtabn(tab, i, TRUE);
				return NULL;
			}

			tab[i][0] = '\0';
		}
		// else set it to NULL
		else
			tab[i] = NULL;
	}

	return (tab);
}
