/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:44:55 by idcornua          #+#    #+#             */
/*   Updated: 2019/06/25 11:05:52 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char					*str;
	int						size = ft_intlen(n);

	// allocate memory, and return NULL if failure
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	
	// check for zero and negative values
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	
	// end the string
	str[size] = '\0';

	// set number as positive
	nb = (n < 0) ? -n : n;

	// and parse it, number by number
	while (nb != 0) {
		str[size - 1] = (nb % 10) + 48;
		nb /= 10;
		size--;
	}

	return (str);
}

/*
** === MAN ft_itoa ===
** -
** DESCRIPTION:
** -
** ft_itoa converti un int en chaine de caracteres.
** -
** ARGUMENTS:
** -
** [int n]:
** un int representant le nombre a convertir.
** -
** RETOUR:
** -
** [char *]
** ft_itoa retourne une chaine de caractere correspondant a la valeur de n.
** -
*/
