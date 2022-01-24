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

void	ft_lstdel(linkedList **head, void (*del)(void *, size_t))
{
	linkedList *next;

	while (*head) {
		next = (*head)->next;
		(*del)((*head)->content, (*head)->contentSize);
		free(*head);
		*head = next;
	}

	*head = NULL;
}

/*
** === MAN ft_lstdel ===
** -
** DESCRIPTION:
** -
** ft_lstdel libere toute la memoire prealablement dynamiquement allouee de
** chaque maillon de la chaine de linkedList pointee par alst.
** -
** ARGUMENTS:
** -
** [linkedList **alst]:
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
