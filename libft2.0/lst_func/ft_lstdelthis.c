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

void	ft_lstdelthis(t_list **head, t_list *to_del)
{
	t_list	*prev;
	t_list	*cursor;

	if (!head || !to_del)
		return ;
	cursor = *head;
	if (*head == to_del)
	{
		*head = cursor->next;
		ft_lstdelone(&to_del, &ft_del);
		return ;
	}
	prev = *head;
	cursor = prev->next;
	while (cursor)
	{
		if (cursor == to_del)
		{
			prev->next = cursor->next;
			ft_lstdelone(&to_del, &ft_del);
			return ;
		}
		prev = cursor;
		cursor = cursor->next;
	}
}

/*
** === MAN ft_lstdelthis ===
** -
** DESCRIPTION:
** -
** ft_lstdelthis libere toute la memoire prealablement dynamiquement allouee
** du maillon to_del apres l'avoir trouvé dans la liste pointee par head,
** puis fait le raccordement entre les maillons restants de la liste.
** -
** ARGUMENTS:
** -
** [t_list **head]:
** un pointeur sur le premier maillon de la liste.
** [t_list *to_del]:
** le maillon a trouver puis liberer.
** -
** RETOUR:
** -
** [void]
** -
*/
