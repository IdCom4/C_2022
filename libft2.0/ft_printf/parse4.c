/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:24:29 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/13 14:53:59 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_repeat(char *str, t_flags *flags)
{
	if (str[0] != 'r')
		return (0);
	if (ft_isdigit(str[1]) || str[1] == '*')
		flags->repeat = (str[1] == '*') ? TO_GET : ft_atoi(&str[1]);
	return (1 + ft_skip(&str[1]));
}

t_flags		*check_neg(t_flags *f)
{
	if (f->min_width < TO_GET || f->format < TO_GET || f->precision < TO_GET
	|| f->t_size < TO_GET || f->repeat < TO_GET)
		ft_error();
	return (f);
}

char		*ft_repeat(char *ret, int rep)
{
	char c;

	if (rep == UNSET)
		return (ret);
	c = ret[0];
	ret = ft_strfill(ft_realloc(ret, rep), c, rep);
	return (ret);
}
