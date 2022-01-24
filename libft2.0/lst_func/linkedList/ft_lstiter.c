/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:43:54 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/15 11:49:36 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(linkedList *head, void (*f)(linkedList *))
{
	if (!f)
		return ;

	while (head) {
		(*f)(head);
		head = head->next;
	}
}

/*
** === MAN ft_lstiter ===
** -
** DESCRIPTION:
** -
** ft_lstiter parcours une liste et applique la fonction f a chacun de ses
** maillons.
** -
** ARGUMENTS:
** -
** [linkedList *head]:
** le premier maillon de la liste.
** [void (*f)(linkedList *)]:
** un pointeur sur la fonction a appliquer sur les maillons de la liste.
** -
** RETOUR:
** -
** [void]
** -
*/
