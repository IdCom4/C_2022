/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:46:39 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/14 13:03:07 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_freeflags(t_flags **head)
{
	t_flags *tmp;
	t_flags *cursor;

	cursor = *head;
	while (cursor)
	{
		if (cursor->base_from)
			free(cursor->base_from);
		if (cursor->base_to)
			free(cursor->base_to);
		if (cursor->x_start)
			free(cursor->x_start);
		if (cursor->x_mid)
			free(cursor->x_mid);
		if (cursor->x_end)
			free(cursor->x_end);
		tmp = cursor->next;
		free(cursor);
		cursor = tmp;
	}
	*head = NULL;
}

static t_flags		*set_flags2(t_flags *flags)
{
	flags->x_format = FALSE;
	flags->l_x_start = FALSE;
	flags->x_start = NULL;
	flags->l_x_mid = FALSE;
	flags->x_mid = NULL;
	flags->l_x_end = FALSE;
	flags->x_end = NULL;
	flags->y_format = FALSE;
	flags->y_start = FALSE;
	flags->y_mid = FALSE;
	flags->y_end = FALSE;
	flags->repeat = UNSET;
	return (flags);
}

static t_flags		*set_flags(void)
{
	t_flags	*flags;
	int		i;

	if (!(flags = (t_flags *)malloc(sizeof(t_flags) * 1)))
		ft_error();
	i = 0;
	while (i < MAX_NBR_OPTIONS)
		flags->options[i++] = FALSE;
	flags->min_width = UNSET;
	flags->precision = UNSET;
	flags->format = UNSET;
	flags->t_size = UNSET;
	flags->size = UNSET;
	flags->type = FALSE;
	flags->option_len = 0;
	flags->color = FALSE;
	flags->color_index = UNSET;
	flags->mod = FALSE;
	flags->base_from = NULL;
	flags->base_to = NULL;
	flags->len_base_from = UNSET;
	flags->len_base_to = UNSET;
	flags->next = NULL;
	return (set_flags2(flags));
}

t_flags				*ft_new_flag(char const *str)
{
	t_flags	*flags;
	int		i;

	i = 0;
	flags = set_flags();
	flags->mod = (str[0] == '%') ? TRUE : FALSE;
	if (str[i] == '{')
		return (get_color(flags, (char *)str));
	i += get_options((char *)&str[i], flags);
	i += get_min_width((char *)&str[i], flags);
	i += get_repeat((char *)&str[i], flags);
	i += get_precision((char *)&str[i], flags);
	i += get_format((char *)&str[i], flags);
	i += get_t_size((char *)&str[i], flags);
	i += get_xy_format((char *)&str[i], flags);
	i += get_base((char *)&str[i], flags);
	i += get_size((char *)&str[i], flags);
	if (ft_strichr(TYPE_C, str[i]) != -1)
		flags->type = str[i++];
	else if (!flags->mod)
		ft_error();
	if (flags->precision == UNSET && flags->type == 'f')
		flags->precision = 6;
	flags->option_len = (flags->mod == TRUE) ? 1 : i;
	return (uniform(check_neg(flags)));
}
