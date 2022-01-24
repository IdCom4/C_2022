/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:52:40 by idcornua          #+#    #+#             */
/*   Updated: 2019/01/21 15:27:52 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

linkedList	*ft_lstnew(void *content, size_t contentSize)
{
	linkedList *newLink;

	if (!(newLink = (linkedList *)malloc(sizeof(linkedList))))
		return (NULL);

	newLink->content = content;
	newLink->contentSize = contentSize;

	newLink->next = NULL;

	return (newLink);
}

/*
** === MAN ft_lstnew ===
** -
** DESCRIPTION:
** -
** ft_lstnew cree un nouveau maillon linkedList avec les arguments qu'elle recoit.
** -
** ARGUMENTS:
** -
** [void const *content]:
** un pointeur sur ce que le nouveau maillon doit contenir.
** [size_t contentSize]:
** la taille de ce que le nouveau maillon doit contenir.
** -
** RETOUR:
** -
** [linkedList *]:
** ft_lstnew renvoie le nouveau maillon precedement cree.
** -
*/
