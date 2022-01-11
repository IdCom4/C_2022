/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:02:54 by idcornua          #+#    #+#             */
/*   Updated: 2019/03/06 16:25:29 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_skip(char *str)
{
	int i;

	i = 0;
	if (str[i] == '*')
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

t_flags			*uniform2(t_flags *flags)
{
	flags->format = (flags->format == 0) ? 1 : flags->format;
	if (flags->options[LINE] && (flags->options[H_INDEX] || flags->y_format))
		ft_error();
	if (flags->format != UNSET && (ft_strichr("cp", flags->type) != -1
	|| flags->options[HTAG] == TRUE))
		ft_error();
	if (flags->format != UNSET && ((flags->precision != UNSET
	&& ft_strichr("sf", flags->type) == -1)))
		ft_error();
	if ((flags->len_base_from != UNSET || flags->len_base_to != UNSET)
	&& flags->type != 'b' && flags->type != 'B')
		ft_error();
	if (flags->len_base_from == UNSET && flags->type == 'b')
		ft_error();
	if ((flags->size > LL && flags->type == 'B')
	|| (flags->size != UNSET && flags->type == 'b'))
		ft_error();
	if (flags->repeat != UNSET && flags->type != 'c')
		ft_error();
	return (flags);
}

t_flags			*uniform(t_flags *flags)
{
	if ((flags->options[INDEX] || flags->options[LINE])
	&& flags->t_size == UNSET)
		ft_error();
	if (flags->options[SPACE] && flags->options[PLUS])
		ft_error();
	if (flags->options[ZERO] && flags->options[MINUS])
		ft_error();
	if (flags->options[HTAG] && ft_strichr("diucspbB", flags->type) != -1)
		ft_error();
	if ((flags->options[PLUS] || flags->options[SPACE])
	&& ft_strichr("ouxXcsp", flags->type) != -1)
		ft_error();
	if (flags->size != UNSET && flags->type == 'p')
		ft_error();
	if (flags->size == UP_L && flags->type != 'f')
		ft_error();
	if (flags->size == HH && ft_strichr("fcsp", flags->type) != -1)
		ft_error();
	if ((flags->size == LL || flags->size == H)
	&& ft_strichr("fcsp", flags->type) != -1)
		ft_error();
	if (flags->precision != UNSET && (flags->type == 'c' || flags->type == 'p'))
		ft_error();
	return (uniform2(flags));
}

void			ft_parse_format(char const *format, t_flags **head)
{
	t_flags	*cursor;
	int		i;

	cursor = NULL;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				ft_error();
			if (!cursor)
			{
				*head = ft_new_flag(&format[i + 1]);
				cursor = *head;
			}
			else
			{
				cursor->next = ft_new_flag(&format[i + 1]);
				cursor = cursor->next;
			}
			i += cursor->option_len;
		}
		i++;
	}
}
