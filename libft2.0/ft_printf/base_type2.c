/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_type2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:56:51 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/14 13:01:09 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_gb_gb(va_list ap, int t_size, t_flags *f)
{
	int		*result;
	int		i;
	char	**tab;

	result = va_arg(ap, int *);
	if (!(tab = ft_mallstrtab(t_size, 0)))
		ft_error();
	i = 0;
	while (i < t_size)
	{
		if (!(tab[i] = ft_from_base_10(result[i], f->base_to, f->len_base_to)))
			ft_error();
		i++;
	}
	return (tab);
}

char	**ft_gb_lb(va_list ap, int t_size, t_flags *f)
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
		if (!(tab[i] = ft_from_base_10(result[i], f->base_to, f->len_base_to)))
			ft_error();
		i++;
	}
	return (tab);
}

char	**ft_gb_llb(va_list ap, int t_size, t_flags *f)
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
		if (!(tab[i] = ft_from_base_10(result[i], f->base_to, f->len_base_to)))
			ft_error();
		i++;
	}
	return (tab);
}

char	**ft_b_b(va_list ap, int t_size, t_flags *f)
{
	char	**result;
	char	**tab;
	int		i;

	result = va_arg(ap, char **);
	if (!(tab = ft_mallstrtab(t_size, 0)))
		ft_error();
	i = 0;
	while (i < t_size)
	{
		if (result[i]
		&& !(tab[i] = ft_base_n_to_x(result[i], f->base_from, f->base_to)))
			ft_error();
		else
			tab[i] = (!result[i]) ? ft_strdupe("(null)") : tab[i];
		i++;
	}
	return (tab);
}
