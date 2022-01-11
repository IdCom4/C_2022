/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_d.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:10:52 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/07 12:17:03 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_d_d(int t_size, va_list ap)
{
	int		*result;
	char	**tab;
	int		i;

	result = va_arg(ap, int *);
	if (!(tab = ft_mallstrtab(t_size, 0)))
		ft_error();
	i = 0;
	while (i < t_size)
	{
		if (!(tab[i] = ft_itoa(result[i])))
			ft_error();
		i++;
	}
	return (tab);
}

char	**ft_d_l(int t_size, va_list ap)
{
	long	*result;
	char	**tab;
	int		i;

	result = va_arg(ap, long *);
	if (!(tab = ft_mallstrtab(t_size, 0)))
		ft_error();
	i = 0;
	while (i < t_size)
	{
		if (!(tab[i] = ft_lltoa(result[i])))
			ft_error();
		i++;
	}
	return (tab);
}

char	**ft_d_ll(int t_size, va_list ap)
{
	long long	*result;
	char		**tab;
	int			i;

	result = va_arg(ap, long long *);
	if (!(tab = ft_mallstrtab(t_size, 0)))
		ft_error();
	i = 0;
	while (i < t_size)
	{
		if (!(tab[i] = ft_lltoa(result[i])))
			ft_error();
		i++;
	}
	return (tab);
}

char	**ft_d_h(int t_size, va_list ap)
{
	short	*result;
	char	**tab;
	int		i;

	result = va_arg(ap, short *);
	if (!(tab = ft_mallstrtab(t_size, 0)))
		ft_error();
	i = 0;
	while (i < t_size)
	{
		if (!(tab[i] = ft_itoa(result[i])))
			ft_error();
		i++;
	}
	return (tab);
}
