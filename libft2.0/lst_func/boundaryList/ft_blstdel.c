/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:15:02 by idcornua          #+#    #+#             */
/*   Updated: 2019/01/21 16:50:36 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_blstdel(boundaryList **head)
{
	boundaryList *next;

	while (*head) {
		next = (*head)->next;
		free(*head);
		*head = next;
	}

	*head = NULL;
}

/*
** === MAN ft_blstdel ===
** -
** DESCRIPTION:
** -
** ft_blstdel libere toute la memoire prealablement dynamiquement allouee de
** chaque maillon de la chaine de boundaryList pointee par head.
** -
** ARGUMENTS:
** -
** [boundaryList **head]:
** un pointeur sur le premier maillon de la chaine.
** -
** RETOUR:
** -
** [void]
** -
*/
