/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 10:32:55 by idcornua          #+#    #+#             */
/*   Updated: 2019/03/07 14:20:07 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fill_y_mid(char *new, char *str, char *fill, int t_size)
{
	int i;

	i = 0;
	while (i != -1)
	{
		new = ft_strcjoinfe(new, &str[i], '\n', 0);
		if (t_size - 1 > 0)
			new = ft_strjoinfe(new, fill, 0);
		i += ft_strichr(&str[i], '\n') + 1;
		if (!str[i])
			break ;
		t_size--;
	}
	return (new);
}

char		*set_y_mid(t_flags *f, char *str, char *new, int len)
{
	int		ind;
	char	*fill;

	if (!f->y_mid)
		return (new);
	ind = (f->options[INDEX]) ? ft_intlen(f->t_size - 1) + 2 : 0;
	fill = ft_strfill(ft_strnew(len + 2 + ind), f->y_mid, len + 2 + ind);
	fill[0] = '\n';
	ft_strfill(&fill[1], ' ', ind);
	fill[ind + 1] = f->y_mid;
	fill[len + 1 + ind] = '\n';
	new = fill_y_mid(new, str, fill, f->t_size);
	free(fill);
	return (new);
}

char		*set_y_end(char *str, char *new, t_flags *f, int len)
{
	char	*fill;
	int		ind;

	if (!f->y_end)
		return (new);
	ind = (f->options[INDEX]) ? ft_intlen(f->t_size - 1) + 2 : 0;
	fill = ft_strfill(ft_strnew(len + 1), f->y_end, len);
	fill[len] = '\n';
	fill = ft_strjoinfe(ft_strfill(ft_strnew(ind), ' ', ind), fill, 2);
	if (f->y_mid)
		fill = ft_strjoinfe("\n", fill, 1);
	if (f->y_start || f->y_mid)
		new = ft_strjoinfe(new, fill, 2);
	else
		new = ft_strjoinfe(str, fill, 1);
	return (new);
}
