/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:44:55 by idcornua          #+#    #+#             */
/*   Updated: 2019/06/25 11:06:27 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa(unsigned long long n)
{
	char			*str;
	int				size = ft_lllen((long long)n, 1);

	// allocate memory, and return NULL if failure
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);

	// check for zero value
	if (n == 0) str[0] = '0';

	// end the string
	str[size] = '\0';

	while (n != 0) {
		str[size - 1] = (n % 10) + 48;
		n /= 10;
		size--;
	}

	return (str);
}

/*
** === MAN ft_ulltoa ===
** -
** DESCRIPTION:
** -
** ft_ulltoa converti un unsigned long long en chaine de caracteres.
** -
** ARGUMENTS:
** -
** [unsigned long long n]:
** un unsigned long long representant le nombre a convertir.
** -
** RETOUR:
** -
** [char *]
** ft_ulltoa retourne une chaine de caractere correspondant a la valeur de n.
** -
*/
