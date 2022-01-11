/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_f.c.                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:35:13 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/14 10:31:27 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_f_f(int t_size, va_list ap)
{
	float	*result;
	char	**tab;
	int		i;

	result = va_arg(ap, float *);
	if (!(tab = ft_mallstrtab(t_size, 0)))
		ft_error();
	i = 0;
	while (i < t_size)
	{
		if (!(tab[i] = ft_ldtoa(result[i])))
			ft_error();
		i++;
	}
	return (tab);
}

char	**ft_f_d(int t_size, va_list ap)
{
	double	*result;
	char	**tab;
	int		i;

	result = va_arg(ap, double *);
	if (!(tab = ft_mallstrtab(t_size, 0)))
		ft_error();
	i = 0;
	while (i < t_size)
	{
		if (!(tab[i] = ft_ldtoa(result[i])))
			ft_error();
		i++;
	}
	return (tab);
}

char	**ft_f_ld(int t_size, va_list ap)
{
	long double	*result;
	char		**tab;
	int			i;

	result = va_arg(ap, long double *);
	if (!(tab = ft_mallstrtab(t_size, 0)))
		ft_error();
	i = 0;
	while (i < t_size)
	{
		if (!(tab[i] = ft_ldtoa(result[i])))
			ft_error();
		i++;
	}
	return (tab);
}
