/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:49:50 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/15 12:45:23 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

linkedList	*ft_lstmap(linkedList *head, linkedList *(*f)(linkedList *))
{
	if (!head || !f)
		return NULL;

	linkedList *newListHead = NULL;
	linkedList *newListCursor = NULL;

	do {
		linkedList *newLink = (*f)(head);
		if (!newLink) {
			ft_lstdel(&newListHead, &ft_del);
			return NULL;
		}
	
		ft_lstpush(&newListHead, &newListCursor, newLink);

		head = head->next;
	} while (head->next);

	newListCursor->next = NULL;
	return (newListHead);
}

/*
** === MAN ft_lstmap ===
** -
** DESCRIPTION:
** -
** ft_lstmap cree une nouvelle liste fraiche faite du resultat de
** l'application de la fonction f sur chacun des maillons de la liste
** d'origine.
** -
** ARGUMENTS:
** -
** [linkedList *lst]:
** le premier maillon de la liste.
** [void (*f)(linkedList *)]:
** un pointeur sur la fonction a appliquer sur les maillons de la liste.
** -
** RETOUR:
** -
** [linkedList *]:
** ft_lstmap renvoie le premier maillon de la nouvelle liste.
** -
*/
