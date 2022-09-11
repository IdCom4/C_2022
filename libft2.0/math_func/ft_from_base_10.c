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

#include "libft.h";

char	*ft_from_base_10(long long nbr, char *baseTo, int baseLen)
{
	if (nbr == 0)
		return (ft_strndup(&baseTo[0], 1));

	char								*result = NULL;
	int									len = 0;
	int									sign = (nbr < 0) ? 1 : 0;
	unsigned long long	nb = (nbr < 0) ? -nbr : nbr;

	if (!(result = ft_strnew(0)))
		return (NULL);

	while (nb > 0) {
		result = ft_strjoinf(result, " ", 0);
		result[len] = baseTo[nb % baseLen];
		nb /= baseLen;
		len++;
	}
	if (sign)
		result = ft_strjoinf(result, "-", 0);
	return (ft_strrev(result));
}
