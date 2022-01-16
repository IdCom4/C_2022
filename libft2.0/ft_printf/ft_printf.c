/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:42:41 by idcornua          #+#    #+#             */
/*   Updated: 2019/04/16 17:34:26 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_min_width(int min_width, t_flags *flags, char *val, int len)
{
	char	*fill;
	int		n;

	n = min_width - len;
	if (flags->options[MINUS])
		val = ft_strjoinfe(val, ft_strfill(ft_strnew(n), ' ', n), 2);
	else if (flags->options[ZERO] && flags->format == UNSET
	&& ((flags->type != 'f' && flags->precision == UNSET)
	|| flags->type == 'f'))
	{
		fill = ft_strfill(ft_strnew(n), '0', n);
		if (ft_strichr("difbB", flags->type) != -1 && !ft_isdigit(val[0]))
			fill = ft_strjoinfe(ft_strndupe(val, 1), fill, 2);
		else if (ft_strichr("xX", flags->type) != -1 && len > 0
		&& flags->options[HTAG] == TRUE)
			fill = ft_strjoinfe(ft_strndupe(val, 2), fill, 2);
		if (!ft_isdigit(fill[0]) || fill[1] == 'x' || fill[1] == 'X')
			val = ft_strshift(val, (!ft_isdigit(fill[0])) ? 1 : 2, START, len);
		val = ft_strjoinfe(fill, val, 2);
	}
	else
		val = ft_strjoinfe(ft_strfill(ft_strnew(n), ' ', n), val, 2);
	return (val);
}

char	*set_htag(char type, char *value)
{
	int i;

	i = 0;
	if (type == 'o')
		value = ft_strjoinfe((value[0] == '0') ? "" : "0", value, 1);
	else if (value[0] != 0)
	{
		while (value[i] == '0')
			i++;
		if (value[i])
			value = ft_strjoinfe((type == 'x') ? "0x" : "0X", value, 1);
	}
	return (value);
}

char	*ft_format_param(t_flags *flags, char *value)
{
	int len;

	len = ft_strlen(value);
	if (flags->precision != UNSET)
		value = ft_precision(flags->precision, flags->type, value, len);
	if (flags->format != UNSET)
		value = nb_format(value, flags, ft_strlen(value));
	if ((flags->options[PLUS] || flags->options[SPACE]) && value[0] != '-')
		value = ft_strjoinfe((flags->options[PLUS]) ? "+" : " ", value, 1);
	if (flags->options[HTAG] && ft_strichr("oxX", flags->type) != -1)
		value = set_htag(flags->type, value);
	if (flags->options[HTAG] && flags->type == 'f'
	&& ft_strichr(value, '.') == -1)
		value = ft_strjoinfe(value, ".", 0);
	len = ft_strlen(value);
	if (flags->min_width > len)
		value = ft_min_width(flags->min_width, flags, value, len);
	return (value);
}

void	ft_algo(char *fmt, char **print, t_flags *cursor, va_list ap)
{
	int		i;
	char	*param;

	while (*fmt != '\0')
	{
		i = ft_strichr(fmt, '%');
		if (i < 0)
		{
			*print = ft_strjoinfe(*print, fmt, 0);
			break ;
		}
		else
		{
			*print = (i > 0) ? ft_strnjoinfe(*print, fmt, i, 0) : *print;
			if (cursor->mod == TRUE || cursor->t_size != UNSET)
				param = (cursor->mod) ? ft_strdupe("%") : ft_tab(cursor, ap);
			else if (cursor->color == FALSE)
				param = ft_format_param(cursor, get_param(ap, cursor));
			else
				param = get_color_code(cursor);
			*print = ft_strjoinfe(*print, param, 2);
			fmt = fmt + i + cursor->option_len + 1;
			cursor = cursor->next;
		}
	}
}

int		ft_printf(char const *format, ...)
{
	t_flags	*flags;
	va_list	ap;
	int		len;
	char	*to_print;

	flags = NULL;
	if (!format || !(to_print = ft_strnew(0)))
		ft_error();
	ft_parse_format(format, &flags);
	va_start(ap, format);
	ft_algo((char *)format, &to_print, flags, ap);
	len = ft_strlen(to_print);
	ft_char_replace(to_print, -1, 0);
	write(1, to_print, len);
	free(to_print);
	ft_freeflags(&flags);
	va_end(ap);
	return (len);
}
