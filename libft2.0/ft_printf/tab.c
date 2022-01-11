/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:44:31 by idcornua          #+#    #+#             */
/*   Updated: 2019/04/12 15:32:33 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_x_format(char *str, t_flags *f, int len)
{
	char	*new;
	int		i;
	int		length;

	length = len + f->l_x_start + f->l_x_mid * (len - 1) + f->l_x_end;
	if (!(new = ft_strnew(length)))
		ft_error();
	if (f->x_start)
		ft_strcat(new, f->x_start);
	if (f->x_start && !f->x_mid)
		ft_strcat(new, str);
	i = -1;
	if (f->x_mid)
	{
		while (++i < len)
		{
			ft_strncat(new, &str[i], 1);
			if (i + 1 < len)
				ft_strcat(new, f->x_mid);
		}
	}
	if (f->x_end)
		ft_strcat(new, f->x_end);
	free(str);
	return (new);
}

static char	*ft_y_format(char *str, t_flags *f, int len)
{
	char	*new;
	char	*fill;
	int		ind;

	ind = (f->options[INDEX]) ? ft_intlen(f->t_size - 1) + 2 : 0;
	if (f->y_start)
	{
		fill = ft_strfill(ft_strnew(ind), ' ', ind);
		new = ft_strfill(ft_strnew(len + 1), f->y_start, len);
		new[len] = '\n';
		new = ft_strjoinfe(fill, new, 2);
	}
	else if (f->y_mid)
		new = ft_strdupe("");
	if (f->y_start && !f->y_mid)
		new = ft_strjoinfe(new, str, 0);
	new = set_y_mid(f, str, new, len);
	new = set_y_end(str, new, f, len);
	free(str);
	if (f->y_mid && !f->y_end)
		free(fill);
	return (new);
}

static char	*format_tab(char *str, int i, t_flags *f, int *max_len)
{
	char	*index;
	int		len;
	int		ilen;
	char	*toa;

	str = ft_format_param(f, str);
	if (f->x_format || f->y_format || f->options[H_INDEX])
		len = ft_strlen(str);
	if (f->x_format == TRUE)
	{
		str = ft_x_format(str, f, len);
		len += f->l_x_start + f->l_x_mid * (len - 1) + f->l_x_end;
	}
	if (f->options[INDEX])
	{
		ilen = ft_intlen(f->t_size - 1);
		index = ft_strfill(ft_strnew(ilen + 2), ' ', ilen + 2);
		index[ilen] = '|';
		ft_strcfill(&index[ilen - ft_intlen(i)], (toa = ft_itoa(i)), ' ', ilen);
		free(toa);
		str = ft_strjoinfe(index, str, 2);
	}
	if (f->y_format == TRUE || f->options[H_INDEX])
		*max_len = (*max_len >= len) ? *max_len : len;
	return (str);
}

char		*ft_tab(t_flags *cursor, va_list ap)
{
	char	**tab;
	char	*final;
	int		i;
	int		max_len;

	tab = get_tab(ap, cursor);
	final = ft_strdupe("");
	i = 0;
	max_len = 0;
	while (i < cursor->t_size)
	{
		final = ft_strjoinfe(final, format_tab(tab[i], i, cursor, &max_len), 2);
		if (cursor->options[LINE] && i + 1 < cursor->t_size)
			final = ft_strjoinfe(final, ", ", 0);
		else if (!cursor->options[LINE])
			final = ft_strjoinfe(final, "\n", 0);
		i++;
	}
	free(tab);
	if (cursor->y_format == TRUE)
		final = ft_y_format(final, cursor, max_len);
	if (cursor->options[H_INDEX])
		final = ft_set_h_index(final, cursor, max_len);
	return (final);
}
