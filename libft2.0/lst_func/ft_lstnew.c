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

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_m;

	if (!(new_m = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(new_m->content = (void *)ft_memalloc(content_size)))
		{
			free(new_m);
			return (NULL);
		}
		ft_memcpy(new_m->content, content, content_size);
		new_m->content_size = content_size;
	}
	else
	{
		new_m->content = NULL;
		new_m->content_size = 0;
	}
	new_m->next = NULL;
	return (new_m);
}

/*
** === MAN ft_lstnew ===
** -
** DESCRIPTION:
** -
** ft_lstnew cree un nouveau maillon t_list avec les arguments qu'elle recoit.
** -
** ARGUMENTS:
** -
** [void const *content]:
** un pointeur sur ce que le nouveau maillon doit contenir.
** [size_t content_size]:
** la taille de ce que le nouveau maillon doit contenir.
** -
** RETOUR:
** -
** [t_list *]:
** ft_lstnew renvoie le nouveau maillon precedement cree.
** -
*/
