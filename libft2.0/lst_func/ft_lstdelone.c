/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:01:37 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/15 11:12:47 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *cursor;

	cursor = *alst;
	(*del)(cursor->content, cursor->content_size);
	free(*alst);
	*alst = NULL;
}

/*
** === MAN ft_lstdelone ===
** -
** DESCRIPTION:
** -
** ft_lstdelone libere toute la memoire prealablement dynamiquement allouee
** d'un maillon pointé par alst.
** -
** ARGUMENTS:
** -
** [t_list **alst]:
** un pointeur sur le maillon a liberer.
** [void (*del)(void *, size_t)]:
** un pointeur sur une fonction liberant la memoire prealablement
** dynamiquement allouee du contenu d'un maillon.
** -
** RETOUR:
** -
** [void]
** -
*/
