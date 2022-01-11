/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:56:47 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/14 12:30:19 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ldtoa(long double nbr)
{
	char			*str;
	long long		exp;
	long double		mantisse;

	if (!(nbr == nbr))
		return (ft_strdup("nan"));
	if (nbr == -1.0 / 0.0 || nbr == 1.0 / 0.0)
		return (ft_strdup((nbr == -1.0 / 0.0) ? "-inf" : "inf"));
	if (1.0 / nbr == -1.0 / 0.0)
		return (ft_strdup("-0"));
	exp = (long long)nbr;
	mantisse = nbr - exp;
	mantisse = (mantisse < 0) ? -mantisse : mantisse;
	if (!(str = ft_lltoa(exp)))
		return (NULL);
	if (mantisse && !(str = ft_strjoinf(str, ".", 0)))
		return (NULL);
	while (mantisse)
	{
		if (!(str = ft_strjoinf(str, ft_itoa((int)(mantisse * 10)), 2)))
			return (NULL);
		mantisse = (mantisse * 10) - (int)(mantisse * 10);
	}
	return (str);
}
