/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelthis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:11:30 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/10 16:26:16 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelthis(linkedList **head, linkedList *toDel, void (*del)(void *, size_t))
{
		if (!head || !toDel)
		return ;
	
	linkedList	*cursor;

	if (*head == toDel) {
		*head = (*head)->next;
		ft_lstdelone(&toDel, del);

		return ;
	}

	cursor = (*head);
	while (cursor) {

		if (cursor->next == toDel) {
			cursor->next = cursor->next->next;
			ft_lstdelone(&toDel, del);

			return ;
		}
		
		cursor = cursor->next;
	}
}

/*
** === MAN ft_lstdelthis ===
** -
** DESCRIPTION:
** -
** ft_lstdelthis libere toute la memoire prealablement dynamiquement allouee
** du maillon toDel apres l'avoir trouvé dans la liste pointee par head,
** puis fait le raccordement entre les maillons restants de la liste.
** -
** ARGUMENTS:
** -
** [linkedList **head]:
** un pointeur sur le premier maillon de la liste.
** [linkedList *toDel]:
** le maillon a trouver puis liberer.
** -
** RETOUR:
** -
** [void]
** -
*/
