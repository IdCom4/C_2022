/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:34:44 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/10 16:01:36 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}

/*
** === MAN ft_lstadd ===
** -
** DESCRIPTION:
** -
** ft_lstadd ajoute un nouveau maillon au debut d'une liste de t_list.
** -
** ARGUMENTS:
** -
** [t_list **alst]:
** un pointeur sur le premier maillon de la chaine.
** [t_list *new]:
** le nouveau maillon a ajouter au debut de la liste.
** -
** RETOUR:
** -
** [void]
** -
*/
