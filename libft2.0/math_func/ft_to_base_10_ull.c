/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_base_10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:23:19 by idcornua          #+#    #+#             */
/*   Updated: 2019/01/21 12:23:28 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_to_base_10_ull(char *nbr, char *baseFrom, int baseLen) {
	unsigned long long	result = 0;
	int nbrLen = ft_strnbrLen(nbr);
	int power = ft_power(baseLen, nbrLen);

	while (*nbr) {
		nbrLen--;
		power /= baseLen;
		result += ft_strichr(baseFrom, *nbr) * power;
		nbr++;
	}

	return (result);
}
