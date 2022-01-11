/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_index.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:55:01 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/14 14:10:39 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_h_ind(char **h_ind, int height, int width)
{
	int w;
	int h;

	w = 0;
	h = 0;
	while (w < width)
	{
		h_ind[h][w] = ' ';
		h = (h + 1 < height) ? h + 1 : 0;
		w = (h == 0) ? w + 1 : w;
	}
}

static char	**fill_h_ind(char **h_ind, t_flags *f, int height, int width)
{
	int		h;
	int		w;
	int		i;
	char	*toa;
	int		n;

	set_h_ind(h_ind, height, width);
	w = f->l_x_start;
	n = 0;
	while (w < width - f->l_x_end)
	{
		if (!(toa = ft_itoa(n++)))
			ft_error();
		h = height - 1;
		i = ft_strlen(toa) - 1;
		while (h >= 0)
		{
			h_ind[h][w] = (i >= 0) ? toa[i] : ' ';
			i--;
			h--;
		}
		free(toa);
		w += f->l_x_mid + 1;
	}
	return (h_ind);
}

static char	*add_ind_prefix(char *ind_prefix, char **h_ind, int h)
{
	int		i;
	char	*final;

	i = 0;
	final = ft_strdupe("");
	while (i < h)
	{
		final = ft_strjoinfe(final, ind_prefix, 0);
		final = ft_strjoinfe(final, h_ind[i], 2);
		final = ft_strjoinfe(final, "\n", 0);
		i++;
	}
	return (final);
}

static char	*add_separator(char *final, char **ind_prefix, int max_len)
{
	final = ft_strjoinfe(final, *ind_prefix, 2);
	*ind_prefix = ft_strfill(ft_strnew(max_len), '_', max_len);
	final = ft_strjoinfe(final, *ind_prefix, 0);
	final = ft_strjoinfe(final, "\n", 0);
	return (final);
}

char		*ft_set_h_index(char *str, t_flags *f, int max_len)
{
	char	*ind_prefix;
	int		height;
	char	**h_ind;
	char	*final;

	height = (f->options[INDEX]) ? ft_intlen(f->t_size - 1) + 2 : 0;
	ind_prefix = ft_strfill(ft_strnew(height), ' ', height);
	height = ft_intlen(max_len);
	if (!(h_ind = ft_mallstrtab(height, max_len)))
		ft_error();
	h_ind = fill_h_ind(h_ind, f, height, max_len);
	final = add_ind_prefix(ind_prefix, h_ind, height);
	if (!f->y_start)
		final = add_separator(final, &ind_prefix, max_len);
	free(h_ind);
	free(ind_prefix);
	final = ft_strjoinfe(final, str, 2);
	return (final);
}
