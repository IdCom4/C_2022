/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_o.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:27:06 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/07 13:18:35 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_o_o(int t_size, va_list ap)
{
	unsigned int	*result;
	char			**tab;
	int				i;

	result = va_arg(ap, unsigned int *);
	if (!(tab = ft_mallstrtab(t_size, 0)))
		ft_error();
	i = 0;
	while (i < t_size)
	{
		if (!(tab[i] = ft_from_base_10_ull(result[i], "01234567", 8)))
			ft_error();
		i++;
	}
	return (tab);
}

char	**ft_o_l(int t_size, va_list ap)
{
	unsigned long	*result;
	char			**tab;
	int				i;

	result = va_arg(ap, unsigned long *);
	if (!(tab = ft_mallstrtab(t_size, 0)))
		ft_error();
	i = 0;
	while (i < t_size)
	{
		if (!(tab[i] = ft_from_base_10_ull(result[i], "01234567", 8)))
			ft_error();
		i++;
	}
	return (tab);
}

char	**ft_o_ll(int t_size, va_list ap)
{
	unsigned long long	*result;
	char				**tab;
	int					i;

	result = va_arg(ap, unsigned long long *);
	if (!(tab = ft_mallstrtab(t_size, 0)))
		ft_error();
	i = 0;
	while (i < t_size)
	{
		if (!(tab[i] = ft_from_base_10_ull(result[i], "01234567", 8)))
			ft_error();
		i++;
	}
	return (tab);
}

char	**ft_o_h(int t_size, va_list ap)
{
	unsigned short	*result;
	char			**tab;
	int				i;

	result = va_arg(ap, unsigned short *);
	if (!(tab = ft_mallstrtab(t_size, 0)))
		ft_error();
	i = 0;
	while (i < t_size)
	{
		if (!(tab[i] = ft_from_base_10_ull(result[i], "01234567", 8)))
			ft_error();
		i++;
	}
	return (tab);
}

char	**ft_o_hh(int t_size, va_list ap)
{
	unsigned char	*result;
	char			**tab;
	int				i;

	result = va_arg(ap, unsigned char *);
	if (!(tab = ft_mallstrtab(t_size, 0)))
		ft_error();
	i = 0;
	while (i < t_size)
	{
		if (!(tab[i] = ft_from_base_10_ull(result[i], "01234567", 8)))
			ft_error();
		i++;
	}
	return (tab);
}
