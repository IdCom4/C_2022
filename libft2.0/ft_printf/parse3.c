/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:44:36 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/14 11:16:28 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_format(char *str, t_flags *flags)
{
	if (str[0] != '\'')
		return (0);
	if (ft_isdigit(str[1]) || str[1] == '*')
		flags->format = (str[1] == '*') ? TO_GET : ft_atoi(&str[1]);
	return (1 + ft_skip(&str[1]));
}

static void	set_y_format(t_flags *flags, int nbp, char param[3])
{
	int index;

	flags->y_format = TRUE;
	index = (nbp == 1) ? 0 : 1;
	if (nbp == 1 || nbp == 3)
		flags->y_mid = (param[index] == '*') ? TO_GET : param[index];
	index = (nbp == 2) ? 1 : 2;
	if (nbp >= 2)
	{
		flags->y_start = (param[0] == '*') ? TO_GET : param[0];
		flags->y_end = (param[index] == '*') ? TO_GET : param[index];
	}
}

static int	set_x_format(char *str, t_flags *f, char param[3][100], int nbp)
{
	int index;

	index = (nbp == 1) ? 0 : 1;
	f->x_format = TRUE;
	if (nbp == 1 || nbp == 3)
	{
		f->l_x_mid = ft_strlen(param[index]);
		f->l_x_mid = (f->l_x_mid == 1 && param[index][0] == '*')
			? TO_GET : f->l_x_mid;
		f->x_mid = (f->l_x_mid == TO_GET) ? NULL : ft_strdupe(param[index]);
	}
	index = (nbp == 2) ? 1 : 2;
	if (nbp >= 2)
	{
		f->l_x_start = ft_strlen(param[0]);
		f->l_x_start = (f->l_x_start == 1 && param[0][0] == '*')
			? TO_GET : f->l_x_start;
		f->x_start = (f->l_x_start == TO_GET)
			? NULL : ft_strdupe(param[0]);
		f->l_x_end = ft_strlen(param[index]);
		f->l_x_end = (f->l_x_end == 1 && param[index][0] == '*')
			? TO_GET : f->l_x_end;
		f->x_end = (f->l_x_end == TO_GET) ? NULL : ft_strdupe(param[index]);
	}
	return (ft_strichr(str, ')') + 1);
}

static void	get_y_format(char *str, t_flags *flags)
{
	char	param[3];
	int		nbr_param;
	int		i;
	int		n;

	i = 0;
	nbr_param = 0;
	while (str[i] != ')' && str[i] != 0 && nbr_param <= 2)
	{
		n = 0;
		if (str[i] != ';' && str[i] != ')' && str[i] != 0)
		{
			param[nbr_param++] = str[i++];
			if (str[i] != ';' && str[i] != ')')
				ft_error();
			i += (str[i] == ';') ? 1 : 0;
		}
	}
	if (!str[i] || str[i] != ')' || nbr_param == 0)
		ft_error();
	set_y_format(flags, nbr_param, param);
}

int			get_xy_format(char *str, t_flags *flags)
{
	char	param[3][100];
	int		nbr_param;
	int		i;
	int		n;

	if (str[0] != '(' || (str[0] == '(' && flags->t_size == UNSET))
		return ((str[0] == '(') ? ft_error() : 0);
	nbr_param = 0;
	i = 1;
	while (str[i] != ')' && str[i] != 0 && nbr_param <= 2 && (n = 0) == 0)
	{
		while (str[i] != ';' && str[i] != ')' && str[i] != '&' && str[i] != 0)
			param[nbr_param][n++] = str[i++];
		i += (str[i] == ';') ? 1 : 0;
		param[nbr_param][n] = 0;
		nbr_param++;
		if (str[i] == '&')
		{
			get_y_format(&str[i + 1], flags);
			break ;
		}
	}
	if (!str[i] || (str[i] != ')' && str[i] != '&') || nbr_param == 0)
		ft_error();
	return (set_x_format(str, flags, param, nbr_param));
}
