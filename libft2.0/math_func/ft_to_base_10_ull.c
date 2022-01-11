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

static int			get_value(char c, char *base)
{
	int i;

	i = 0;
	while (c != base[i] && base[i] != '\0')
		i++;
	return (i);
}

unsigned long long	ft_to_base_10_ull(char *nbr, char *base_from, int base_len)
{
	int					len;
	unsigned long long	result;

	result = 0;
	len = ft_strlen(nbr);
	while (*nbr != '\0')
	{
		len--;
		result += get_value(*nbr, base_from) * ft_power(base_len, len);
		nbr = nbr + 1;
	}
	return (result);
}
