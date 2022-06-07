/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:09:20 by idcornua          #+#    #+#             */
/*   Updated: 2019/01/17 18:15:43 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i = 0;
	long	result = 0;
	int		sign = 1;

	// skip all non numeric chars
	while (str[i] != '\0'
		&& ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;

	// then check for a sign and store the data if there is
	if (str[i] == '-')
		sign = -1;
	else if (str[i] == '+')
		i++;

	// skip it if we found it
	i = (sign == 1) ? i : i + 1;

	// now parse the value as long as chars are numbers
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	
	// return the signed parsed value
	return (result * sign);
}

/*
** === MAN ft_atoi ===
** -
** DESCRIPTION:
** ft_atoi converti une chaine de caracteres en sa valeur en int.
** -
** ARGUMENTS:
** [const char *str]:
** un pointeur sur le debut de la chaine de caracteres a convertir.
** -
** RETOUR:
** [int]
** ft_atoi renvoie un int correspondant a la chaine de caracteres, ou 0 si elle
** ne commence pas ou n'a pas du tout de valeur chiffree.
*/
