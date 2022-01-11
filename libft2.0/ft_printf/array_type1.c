/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_type1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:09:34 by idcornua          #+#    #+#             */
/*   Updated: 2019/04/12 15:32:50 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_t_d(int t_size, int size, va_list ap)
{
	if (size == UNSET)
		return (ft_d_d(t_size, ap));
	else if (size == LOW_L)
		return (ft_d_l(t_size, ap));
	else if (size == LL)
		return (ft_d_ll(t_size, ap));
	else if (size == H)
		return (ft_d_h(t_size, ap));
	else
		return (ft_t_c(t_size, size, ap));
	return (NULL);
}

char	**ft_t_o(int t_size, int size, va_list ap)
{
	if (size == UNSET)
		return (ft_o_o(t_size, ap));
	else if (size == LOW_L)
		return (ft_o_l(t_size, ap));
	else if (size == LL)
		return (ft_o_ll(t_size, ap));
	else if (size == H)
		return (ft_o_h(t_size, ap));
	else
		return (ft_o_hh(t_size, ap));
	return (NULL);
}

char	**ft_t_u(int t_size, int size, va_list ap)
{
	if (size == UNSET)
		return (ft_u_u(t_size, ap));
	else if (size == LOW_L)
		return (ft_u_l(t_size, ap));
	else if (size == LL)
		return (ft_u_ll(t_size, ap));
	else if (size == H)
		return (ft_u_h(t_size, ap));
	else
		return (ft_u_hh(t_size, ap));
	return (NULL);
}

char	**ft_t_x(int t_size, int size, va_list ap)
{
	if (size == UNSET)
		return (ft_x_x(t_size, ap));
	else if (size == LOW_L)
		return (ft_x_l(t_size, ap));
	else if (size == LL)
		return (ft_x_ll(t_size, ap));
	else if (size == H)
		return (ft_x_h(t_size, ap));
	else
		return (ft_x_hh(t_size, ap));
	return (NULL);
}

char	**ft_t_gx(int t_size, int size, va_list ap)
{
	if (size == UNSET)
		return (ft_gx_gx(t_size, ap));
	else if (size == LOW_L)
		return (ft_gx_l(t_size, ap));
	else if (size == LL)
		return (ft_gx_ll(t_size, ap));
	else if (size == H)
		return (ft_gx_h(t_size, ap));
	else
		return (ft_gx_hh(t_size, ap));
	return (NULL);
}
