/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:34:44 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/10 16:01:36 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(linkedList **head, linkedList **cursor, linkedList *new)
{
	if (!*head)
		*head = new;
	else
		(*cursor)->next = new;

	*cursor = new;
}

/*
** === MAN ft_lstpush ===
** -
** DESCRIPTION:
** -
** ft_lstpush ajoute un nouveau maillon à la fin d'une liste de linkedList.
** -
** ARGUMENTS:
** -
** [linkedList **alst]:
** un pointeur sur le premier maillon de la chaine.
** [linkedList *new]:
** le nouveau maillon a ajouter à la fin de la liste.
** -
** RETOUR:
** -
** [void]
** -
*/
