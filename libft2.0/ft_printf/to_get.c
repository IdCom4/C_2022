/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:03:29 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/13 14:44:57 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_b(t_flags *curr, va_list ap)
{
	if (curr->type == 'b' || curr->type == 'B')
	{
		if (curr->len_base_from == 1)
		{
			curr->base_from = ft_strdupfe(va_arg(ap, char *), curr->base_from);
			curr->len_base_from = ft_strlen(curr->base_from);
		}
		if (curr->len_base_to == 1)
		{
			curr->base_to = ft_strdupfe(va_arg(ap, char *), curr->base_to);
			curr->len_base_to = ft_strlen(curr->base_to);
		}
	}
}

static void	get_xy_format_star(t_flags *curr, va_list ap)
{
	if (curr->l_x_start == TO_GET)
	{
		curr->x_start = ft_strdupe(va_arg(ap, char *));
		curr->l_x_start = ft_strlen(curr->x_start);
	}
	if (curr->l_x_mid == TO_GET)
	{
		curr->x_mid = ft_strdupe(va_arg(ap, char *));
		curr->l_x_mid = ft_strlen(curr->x_mid);
	}
	if (curr->l_x_end == TO_GET)
	{
		curr->x_end = ft_strdupe(va_arg(ap, char *));
		curr->l_x_end = ft_strlen(curr->x_end);
	}
	if (curr->y_start == TO_GET)
		curr->y_start = (char)va_arg(ap, int);
	if (curr->y_mid == TO_GET)
		curr->y_mid = (char)va_arg(ap, int);
	if (curr->y_end == TO_GET)
		curr->y_end = (char)va_arg(ap, int);
}

void		get_to_get2(va_list ap, t_flags *curr)
{
	if (curr->t_size == TO_GET)
	{
		if ((curr->t_size = va_arg(ap, int)) < 0)
			ft_error();
	}
}

void		get_to_get(va_list ap, t_flags *curr)
{
	if (curr->min_width == TO_GET)
	{
		if ((curr->min_width = va_arg(ap, int)) < 0)
			ft_error();
	}
	if (curr->repeat == TO_GET)
	{
		if ((curr->repeat = va_arg(ap, int)) < 1)
			ft_error();
	}
	if (curr->precision == TO_GET)
	{
		if ((curr->precision = va_arg(ap, int)) < 0)
			ft_error();
	}
	if (curr->format == TO_GET)
	{
		if ((curr->format = va_arg(ap, int)) < 1)
			ft_error();
	}
	get_to_get2(ap, curr);
	get_xy_format_star(curr, ap);
	get_b(curr, ap);
}
