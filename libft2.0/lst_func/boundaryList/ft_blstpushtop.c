/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstpushtop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:34:44 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/10 16:01:36 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_blstpushtop(boundaryList **head, boundaryList *new)
{

	if (*head)
		new->next = *head;

	*head = new;

}

/*
** === MAN ft_blstpushtop ===
** -
** DESCRIPTION:
** -
** ft_blstpushtop ajoute un nouveau maillon au debut d'une liste de boundaryList.
** -
** ARGUMENTS:
** -
** [boundaryList **alst]:
** un pointeur sur le premier maillon de la chaine.
** [boundaryList *new]:
** le nouveau maillon a ajouter au debut de la liste.
** -
** RETOUR:
** -
** [void]
** -
*/
