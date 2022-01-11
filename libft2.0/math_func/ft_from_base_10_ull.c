/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_from_base_10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:38:50 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/06 14:59:26 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_from_base_10_ull(unsigned long long nbr, char *base_to, int b_len)
{
	char	*result;
	int		len;

	if (nbr == 0)
		return (ft_strdup("0"));
	if (!(result = ft_strnew(0)))
		return (NULL);
	len = 0;
	while (nbr > 0)
	{
		result = ft_strjoinf(result, " ", 0);
		result[len] = base_to[nbr % b_len];
		nbr /= b_len;
		len++;
	}
	return (ft_strrev(result));
}
