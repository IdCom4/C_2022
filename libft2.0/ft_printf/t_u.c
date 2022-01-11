/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_u.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:27:06 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/07 13:22:57 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_u_u(int t_size, va_list ap)
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
		if (!(tab[i] = ft_ulltoa(result[i])))
			ft_error();
		i++;
	}
	return (tab);
}

char	**ft_u_l(int t_size, va_list ap)
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
		if (!(tab[i] = ft_ulltoa(result[i])))
			ft_error();
		i++;
	}
	return (tab);
}

char	**ft_u_ll(int t_size, va_list ap)
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
		if (!(tab[i] = ft_ulltoa(result[i])))
			ft_error();
		i++;
	}
	return (tab);
}

char	**ft_u_h(int t_size, va_list ap)
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
		if (!(tab[i] = ft_ulltoa(result[i])))
			ft_error();
		i++;
	}
	return (tab);
}

char	**ft_u_hh(int t_size, va_list ap)
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
		if (!(tab[i] = ft_ulltoa(result[i])))
			ft_error();
		i++;
	}
	return (tab);
}
