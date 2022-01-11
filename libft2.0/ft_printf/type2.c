/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:35:13 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/13 14:54:11 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_f(int size, va_list ap)
{
	long double result;

	if (size == UNSET || size == LOW_L)
		result = (size == UNSET) ? va_arg(ap, double) : va_arg(ap, double);
	else
		result = va_arg(ap, long double);
	return (ft_ldtoa(result));
}

char	*ft_c(int size, va_list ap)
{
	char result;
	char *str;

	(void)size;
	result = (char)va_arg(ap, int);
	str = ft_strdupe(" ");
	str[0] = (result == 0) ? -1 : result;
	return (str);
}

char	*ft_s(int size, va_list ap)
{
	char *result;

	(void)size;
	result = va_arg(ap, char *);
	result = ft_strdupe((result) ? result : "(null)");
	return (result);
}

char	*ft_p(int size, va_list ap)
{
	unsigned long long	result;
	char				*to_return;

	(void)size;
	result = va_arg(ap, unsigned long long);
	to_return = ft_from_base_10_ull(result, "0123456789abcdef", 16);
	return (ft_strjoinfe("0x", to_return, 1));
}

char	*get_param(va_list ap, t_flags *curr)
{
	char	*(*tab[10])(int, va_list);
	char	*ret;

	get_to_get(ap, curr);
	if (curr->type == 'b' || curr->type == 'B')
	{
		if (!(ret = ft_b(ap, curr, curr->size)))
			ft_error();
		return (ret);
	}
	tab[0] = ft_d;
	tab[1] = ft_d;
	tab[2] = ft_o;
	tab[3] = ft_u;
	tab[4] = ft_x;
	tab[5] = ft_gx;
	tab[6] = ft_f;
	tab[7] = ft_c;
	tab[8] = ft_s;
	tab[9] = ft_p;
	ret = tab[ft_strichr(TYPE_C, curr->type)](curr->size, ap);
	ret = ft_repeat(ret, curr->repeat);
	if (!ret)
		ft_error();
	return (ret);
}
