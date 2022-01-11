/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:27:42 by idcornua          #+#    #+#             */
/*   Updated: 2018/12/06 17:02:13 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrf(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (ft_strndel(s, 1, i));
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (ft_strndel(s, 1, i));
	return (NULL);
}

/*
** === MAN ft_strchrf ===
** -
** DESCRIPTION:
** -
** ft_strchrf parcours une chaine de caracteres jusqu'a trouver le caractere
** c ou l'octet nul de fin, et libere la zone memoire precedent le caratere c
** s'il l'a trouvé.
** -
** ARGUMENTS:
** -
** [char *s]:
** un pointeur sur le debut de la chaine de caracteres.
** [int c]:
** le caractere a trouver dans la chaine pointee par s.
** -
** RETOUR:
** -
** [char *]:
** ft_strchrf renvoie un pointeur sur l'adresse suivant celle du caratere c
** dans s s'il l'a trouvé, NULL sinon.
** -
*/
