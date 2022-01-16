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

void		*ft_mallstrtab(size_t tab_size, size_t str_size)
{
	char		**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * tab_size)) || str_size <= 0)
		return (tab);


	for (int i = 0; i < tab_size; i++) {
		if (str_size > 0) {

			if (!(tab[i] = ft_strnew(str_size))) {
        ft_freestrtabn(tab, i, TRUE);
        return NULL;
      }

      tab[i][0] = '\0';
		}
		else
			tab[i] = NULL;
	}

	return (tab);
}
