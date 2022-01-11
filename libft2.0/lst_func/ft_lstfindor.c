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

t_list	*ft_lstfindor(t_list *head, size_t cs, void *content)
{
	t_list *cursor;

	cursor = head;
	while (cursor)
	{
		if (content && ft_strlen(cursor->content) == ft_strlen(content)
		&& !ft_memcmp(cursor->content, content, cursor->content_size))
			return (cursor);
		else if (!content && cursor->content_size == cs)
			return (cursor);
		cursor = cursor->next;
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
** content_size correspond a l'argument cs.
** -
** ARGUMENTS:
** -
** [t_list *head]:
** le premier maillon de la liste.
** [size_t cs]:
** le content_size a trouver si l'argument content est a NULL.
** [void *content]:
** le content a trouver.
** -
** RETOUR:
** -
** [t_list *]:
** ft_lstfindor retourne le maillon dont la proprieté correspond a
** l'argument qu'on a voulu tester.
** -
*/
