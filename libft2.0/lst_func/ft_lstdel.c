/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:15:02 by idcornua          #+#    #+#             */
/*   Updated: 2019/01/21 16:50:36 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *cursor;

	cursor = *alst;
	while (cursor)
	{
		temp = cursor->next;
		(*del)(cursor->content, cursor->content_size);
		free(cursor);
		cursor = temp;
	}
	*alst = NULL;
}

/*
** === MAN ft_lstdel ===
** -
** DESCRIPTION:
** -
** ft_lstdel libere toute la memoire prealablement dynamiquement allouee de
** chaque maillon de la chaine de t_list pointee par alst.
** -
** ARGUMENTS:
** -
** [t_list **alst]:
** un pointeur sur le premier maillon de la chaine.
** [void (*del)(void *, size_t)]:
** un pointeur sur une fonction liberant la memoire prealablement
** dynamiquement allouee du contenu d'un maillon.
** -
** RETOUR:
** -
** [void]
** -
*/
