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

long long		ft_to_base_10(char *nbr, char *base_from, int base_len)
{
	char				*nb;
	int					len;
	unsigned long long	result;
	int					neg;

	result = 0;
	neg = (nbr[0] == '-') ? -1 : 1;
	nb = (nbr[0] == '-') ? nbr + 1 : nbr;
	len = ft_strlen(nb);
	while (*nb != '\0')
	{
		len--;
		result += get_value(*nb, base_from) * ft_power(base_len, len);
		nb = nb + 1;
	}
	return ((long long)(result * neg));
}
