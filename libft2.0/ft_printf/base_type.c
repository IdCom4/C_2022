/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:59:20 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/13 13:42:46 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_base(char *str, t_flags *flags)
{
	int colon;
	int close;

	if (str[0] != '[')
		return (0);
	colon = ft_strichr(str, ';');
	if (colon != UNSET && colon < 2)
		ft_error();
	if (colon != UNSET)
	{
		flags->base_from = ft_strndupe(&str[1], colon - 1);
		if ((flags->len_base_from = ft_strlen(flags->base_from)) == 1
		&& flags->base_from[0] != '*')
			ft_error();
	}
	else
		colon = 0;
	if ((close = ft_strichr(str, ']')) < ((colon == 0) ? 2 : 4))
		ft_error();
	flags->base_to = ft_strndupe(&str[colon + 1], close - colon - 1);
	if ((flags->len_base_to = ft_strlen(flags->base_to)) == 1
	&& flags->base_to[0] != '*')
		ft_error();
	return (close + 1);
}

char	*ft_b(va_list ap, t_flags *curr, int size)
{
	long long	ll_res;
	char		*c_res;

	if (curr->type == 'b')
		c_res = va_arg(ap, char *);
	else
	{
		if (size == UNSET)
			ll_res = va_arg(ap, int);
		else if (size == LOW_L)
			ll_res = va_arg(ap, long);
		else
			ll_res = va_arg(ap, long long);
	}
	if (curr->type == 'b' && !c_res)
		ft_error();
	if (curr->type == 'B')
		return (ft_from_base_10(ll_res, curr->base_to, curr->len_base_to));
	return (ft_base_n_to_x(c_res, curr->base_from, curr->base_to));
}

char	**ft_t_b(va_list ap, t_flags *curr, int t_size, int size)
{
	if (curr->type == 'b')
		return (ft_b_b(ap, t_size, curr));
	else if (size == UNSET)
		return (ft_gb_gb(ap, t_size, curr));
	else if (size == LOW_L)
		return (ft_gb_lb(ap, t_size, curr));
	else
		return (ft_gb_llb(ap, t_size, curr));
	return (NULL);
}
