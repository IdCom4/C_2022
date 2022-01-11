/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 10:16:40 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/14 11:12:41 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*fill_nb_format(char *value, int nbr_zero)
{
	char *new;

	new = ft_strdupe((value[0] == '-') ? "-" : "");
	value[0] = (value[0] == '-') ? '0' : value[0];
	new = ft_strjoinfe(new, ft_strfill(ft_strnew(nbr_zero), '0', nbr_zero), 2);
	return (ft_strjoinfe(new, value, 2));
}

char		*ft_add_mem(char *str, int extra_mem, int old_len)
{
	char *tmp;

	tmp = ft_strfill(ft_strnew(extra_mem + 1), ' ', extra_mem + 1);
	str = ft_strjoinfe(str, tmp, 2);
	ft_strfill(&str[old_len], '\0', extra_mem);
	return (str);
}

char		*nb_format(char *value, t_flags *f, int len)
{
	int end;
	int i;
	int nbr_spaces;
	int mem;

	end = (f->type == 'f') ? ft_strichr(value, '.') : len - 1;
	end = (end == -1) ? len - 1 : end;
	i = (ft_strichr("difbB", f->type) != -1 && value[0] == '-') ? 1 : 0;
	nbr_spaces = (end - i) / f->format;
	value = ft_add_mem(value, nbr_spaces, len);
	i = end + nbr_spaces + 1;
	mem = end + nbr_spaces;
	while (--i >= (value[0] == '-'))
	{
		if ((mem - i) % (f->format + 1) == f->format)
		{
			value[i] = ' ';
			nbr_spaces--;
		}
		else
			value[i] = value[i - nbr_spaces];
	}
	if (f->options[ZERO] && (end - (value[0] == '-') + 1) % f->format != 0)
		value = fill_nb_format(value, (f->format - ((end + 1) % f->format)));
	return (value);
}
