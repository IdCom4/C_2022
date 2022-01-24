/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_base_10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:23:19 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/12 17:08:33 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_value(char c, char *base)
{
	int i;

	i = 0;
	while (c != base[i] && base[i] != '\0')
		i++;
	return (i);
}

long long		ft_to_base_10(char *nbr, char *baseFrom, int baseLen)
{
	long long		result = 0;
	int					sign = (nbr[0] == '-') ? -1 : 1;
	char				*nb = (nbr[0] == '-') ? nbr + 1 : nbr;
	int					nbrLen = ft_strlen(nb);
	int					power = ft_power(baseLen, nbrLen);

	while (*nb) {
		nbrLen--;
		power /= baseLen;
		result += ft_strichr(baseFrom, *nb) * power;
		nb++;
	}

	return (result * sign);
}
