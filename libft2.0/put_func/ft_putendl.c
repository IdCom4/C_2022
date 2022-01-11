/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:51:47 by idcornua          #+#    #+#             */
/*   Updated: 2018/11/13 14:53:26 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}

/*
** === MAN ft_putendl ===
** -
** DESCRIPTION:
** -
** ft_putendl affiche la chaine de caracteres s suivie d'un retour a la ligne.
** -
** ARGUMENTS:
** -
** [char const *s]:
** la chaine de caracteres a afficher.
** -
** RETOUR:
** -
** [void]
** -
*/
