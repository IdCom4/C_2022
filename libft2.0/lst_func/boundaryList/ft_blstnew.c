/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:52:40 by idcornua          #+#    #+#             */
/*   Updated: 2019/01/21 15:27:52 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

boundaryList	*ft_blstnew(size_t start, size_t end)
{
	boundaryList *newLink;

	if (!(newLink = (boundaryList *)malloc(sizeof(boundaryList))))
		return (NULL);

	newLink->start = start;
	newLink->end = end;

	newLink->next = NULL;

	return (newLink);
}

/*
** === MAN ft_blstnew ===
** -
** DESCRIPTION:
** -
** ft_blstnew cree un nouveau maillon boundaryList avec les arguments qu'elle recoit.
** -
** ARGUMENTS:
** -
** [size_t start]:
** une valeur que le nouveau maillon doit contenir.
** [size_t contentSize]:
** une valeur que le nouveau maillon doit contenir.
** -
** RETOUR:
** -
** [boundaryList *]:
** ft_blstnew renvoie le nouveau maillon precedement cree.
** -
*/
