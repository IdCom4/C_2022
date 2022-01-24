/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushtop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:34:44 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/10 16:01:36 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushtop(linkedList **head, linkedList *new)
{

	if (*head)
		new->next = *head;

	*head = new;

}

/*
** === MAN ft_lstpushtop ===
** -
** DESCRIPTION:
** -
** ft_lstpushtop ajoute un nouveau maillon au debut d'une liste de linkedList.
** -
** ARGUMENTS:
** -
** [linkedList **alst]:
** un pointeur sur le premier maillon de la chaine.
** [linkedList *new]:
** le nouveau maillon a ajouter au debut de la liste.
** -
** RETOUR:
** -
** [void]
** -
*/
