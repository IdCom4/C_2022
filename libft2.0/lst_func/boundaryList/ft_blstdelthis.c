/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstdelthis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:11:30 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/10 16:26:16 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_blstdelthis(boundaryList **head, boundaryList *toDel)
{
	if (!head || !toDel)
		return ;
	
	boundaryList	*cursor;

	if (*head == toDel) {
		*head = (*head)->next;
		ft_blstdelone(&toDel);

		return ;
	}

	cursor = (*head);
	while (cursor) {

		if (cursor->next == toDel) {
			cursor->next = cursor->next->next;
			ft_blstdelone(&toDel);

			return ;
		}
		
		cursor = cursor->next;
	}
}

/*
** === MAN ft_blstdelthis ===
** -
** DESCRIPTION:
** -
** ft_blstdelthis libere toute la memoire prealablement dynamiquement allouee
** du maillon toDel apres l'avoir trouvé dans la liste pointee par head,
** puis fait le raccordement entre les maillons restants de la liste.
** -
** ARGUMENTS:
** -
** [boundaryList **head]:
** un pointeur sur le premier maillon de la liste.
** [boundaryList *toDel]:
** le maillon a trouver puis liberer.
** -
** RETOUR:
** -
** [void]
** -
*/
