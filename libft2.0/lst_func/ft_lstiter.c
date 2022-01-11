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

void	ft_lstiter(t_list *lst, void (*f)(t_list *))
{
	if (!f)
		return ;
	while (lst)
	{
		(*f)(lst);
		lst = lst->next;
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
** [t_list *lst]:
** le premier maillon de la liste.
** [void (*f)(t_list *)]:
** un pointeur sur la fonction a appliquer sur les maillons de la liste.
** -
** RETOUR:
** -
** [void]
** -
*/
