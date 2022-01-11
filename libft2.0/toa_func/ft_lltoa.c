/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:44:55 by idcornua          #+#    #+#             */
/*   Updated: 2019/06/25 11:06:16 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa(long long n)
{
	char				*str;
	int					size;
	unsigned long long	nb;

	size = ft_lllen(n, 0);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	str[size] = '\0';
	nb = (n < 0) ? -n : n;
	while (nb != 0)
	{
		str[size - 1] = (nb % 10) + 48;
		nb /= 10;
		size--;
	}
	return (str);
}

/*
** === MAN ft_lltoa ===
** -
** DESCRIPTION:
** -
** ft_lltoa converti un long long en chaine de caracteres.
** -
** ARGUMENTS:
** -
** [long long n]:
** un long long representant le nombre a convertir.
** -
** RETOUR:
** -
** [char *]
** ft_lltoa retourne une chaine de caractere correspondant a la valeur de n.
** -
*/
