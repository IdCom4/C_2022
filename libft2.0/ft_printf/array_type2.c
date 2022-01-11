/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_type2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:35:13 by idcornua          #+#    #+#             */
/*   Updated: 2019/04/12 15:37:19 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_t_f(int t_size, int size, va_list ap)
{
	if (size == UNSET)
		return (ft_f_f(t_size, ap));
	if (size == LOW_L)
		return (ft_f_d(t_size, ap));
	else
		return (ft_f_ld(t_size, ap));
	return (NULL);
}

char	**ft_t_c(int t_size, int size, va_list ap)
{
	char	*result;
	char	**tab;
	int		i;

	(void)size;
	result = va_arg(ap, char *);
	if (!(tab = ft_mallstrtab(t_size, 0)))
		ft_error();
	i = 0;
	while (i < t_size)
	{
		if (!(tab[i] = ft_strdupe(" ")))
			ft_error();
		tab[i][0] = (result == 0) ? -1 : result[i];
		i++;
	}
	return (tab);
}

char	**ft_t_s(int t_size, int size, va_list ap)
{
	char	**result;
	char	**tab;
	int		i;

	(void)size;
	result = va_arg(ap, char **);
	if (!(tab = ft_mallstrtab(t_size, 0)))
		ft_error();
	i = 0;
	while (i < t_size)
	{
		tab[i] = ft_strdupe((result[i]) ? result[i] : "(null)");
		i++;
	}
	return (tab);
}

char	**ft_t_p(int t_size, int size, va_list ap)
{
	unsigned long long	*result;
	char				*str;
	char				**tab;
	int					i;

	(void)size;
	result = va_arg(ap, unsigned long long *);
	if (!(tab = ft_mallstrtab(t_size, 0)))
		ft_error();
	i = 0;
	while (i < t_size)
	{
		str = ft_from_base_10_ull(result[i], "0123456789abcdef", 16);
		tab[i] = ft_strjoinfe("0x", str, 1);
		i++;
	}
	return (tab);
}

char	**get_tab(va_list ap, t_flags *curr)
{
	char	**(*tab[10])(int t_size, int, va_list);
	char	**ret;

	get_to_get(ap, curr);
	if (curr->type == 'b' || curr->type == 'B')
	{
		if (!(ret = ft_t_b(ap, curr, curr->t_size, curr->size)))
			ft_error();
		return (ret);
	}
	tab[0] = ft_t_d;
	tab[1] = ft_t_d;
	tab[2] = ft_t_o;
	tab[3] = ft_t_u;
	tab[4] = ft_t_x;
	tab[5] = ft_t_gx;
	tab[6] = ft_t_f;
	tab[7] = ft_t_c;
	tab[8] = ft_t_s;
	tab[9] = ft_t_p;
	ret = tab[ft_strichr(TYPE_C, curr->type)](curr->t_size, curr->size, ap);
	if (!ret)
		ft_error();
	return (ret);
}
