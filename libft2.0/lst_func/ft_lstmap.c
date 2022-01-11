/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:49:50 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/15 12:45:23 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	void	(*del)(void *, size_t);
	t_list	*head;
	t_list	*cursor;

	del = ft_del;
	if (!lst || !f)
		return (NULL);
	head = (*f)(lst);
	cursor = head;
	lst = lst->next;
	while (lst)
	{
		cursor->next = (*f)(lst);
		if (!cursor->next)
		{
			ft_lstdel(&head, del);
			return (NULL);
		}
		lst = lst->next;
		cursor = cursor->next;
	}
	cursor->next = NULL;
	return (head);
}

/*
** === MAN ft_lstmap ===
** -
** DESCRIPTION:
** -
** ft_lstmap cree une nouvelle liste fraiche faite du resultat de
** l'application de la fonction f sur chacun des maillons de la liste
** d'origine.
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
** [t_list *]:
** ft_lstmap renvoie le premier maillon de la nouvelle liste.
** -
*/
