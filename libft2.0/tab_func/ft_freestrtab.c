/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrtab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:00:59 by idcornua          #+#    #+#             */
/*   Updated: 2019/07/12 14:37:04 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freestrtab(char **tab) {

	if (!tab) return ;
	
	for (size_t i = 0; tab[i]; i++)
		free(tab[i]);

	free(tab);
}

/*
** === MAN ft_freestrtab ===
** -
** DESCRIPTION:
** -
** ft_freestrtab libere la memoire prealablement dynamiquement allouee de
** chaque chaine de caracteres pointees par tab
** -
** ARGUMENTS:
** -
** [char **tab]:
** un pointeur sur la premiere chaine de caracteres a liberer.
** -
** RETOUR:
** -
** [void]
** -
*/
