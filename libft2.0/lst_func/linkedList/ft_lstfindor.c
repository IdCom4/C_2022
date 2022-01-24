/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:39:21 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/10 16:47:50 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

linkedList	*ft_lstfindor(linkedList *head, size_t cs, void *content)
{
	while (head)
	{
		if (content && ft_memcmp(head->content, content, head->contentSize) == 0)
			return (head);
		else if (!content && head->contentSize == cs)
			return (head);

		head = head->next;
	}

	return (NULL);
}

/*
** === MAN ft_lstfindor ===
** -
** DESCRIPTION:
** -
** ft_lstfindor cherche le maillon dans la liste dont le content correspond
** au contenu pointé par l'argument content, ou si content est NULL dont le
** contentSize correspond a l'argument cs.
** -
** ARGUMENTS:
** -
** [linkedList *head]:
** le premier maillon de la liste.
** [size_t cs]:
** le contentSize a trouver si l'argument content est a NULL.
** [void *content]:
** le content a trouver.
** -
** RETOUR:
** -
** [linkedList *]:
** ft_lstfindor retourne le maillon dont la proprieté correspond a
** l'argument qu'on a voulu tester.
** -
*/
