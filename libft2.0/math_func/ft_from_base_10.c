/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_from_base_10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:38:50 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/14 12:29:27 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_from_base_10(long long nbr, char *base_to, int base_len)
{
	char				*result;
	int					len;
	int					neg;
	unsigned long long	nb;

	if (nbr == 0)
		return (ft_strdup("0"));
	if (!(result = ft_strnew(0)))
		return (NULL);
	neg = (nbr < 0) ? 1 : 0;
	nb = (nbr < 0) ? -nbr : nbr;
	len = 0;
	while (nb > 0)
	{
		result = ft_strjoinf(result, " ", 0);
		result[len] = base_to[nb % base_len];
		nb /= base_len;
		len++;
	}
	if (neg)
		result = ft_strjoinf(result, "-", 0);
	return (ft_strrev(result));
}
