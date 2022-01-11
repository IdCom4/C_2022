/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:02:54 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/14 11:57:16 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_precision(char *str, t_flags *flags)
{
	if (str[0] != '.')
		return (0);
	if (ft_isdigit(str[1]) || str[1] == '*')
		flags->precision = (str[1] == '*') ? TO_GET : ft_atoi(&str[1]);
	else
		flags->precision = 0;
	return (1 + ft_skip(&str[1]));
}

int			get_t_size(char *str, t_flags *flags)
{
	if (str[0] != ',')
		return (0);
	if (ft_isdigit(str[1]) || str[1] == '*')
		flags->t_size = (str[1] == '*') ? TO_GET : ft_atoi(&str[1]);
	return (1 + ft_skip(&str[1]));
}

int			get_min_width(char *str, t_flags *flags)
{
	int i;

	if (ft_isdigit(str[0]) || str[0] == '*')
		flags->min_width = (str[0] == '*') ? TO_GET : ft_atoi(str);
	i = (flags->min_width > 0) ? ft_intlen(flags->min_width) : 0;
	i += (flags->min_width == TO_GET) ? 1 : 0;
	return (i);
}

int			get_options(char *str, t_flags *flags)
{
	int i;

	i = 0;
	while (ft_strichr(OPTION_C, str[i]) != -1 && str[i] != '\0')
		i += ((flags->options[ft_strichr(OPTION_C, str[i])] = TRUE)) ? 1 : 0;
	return (i);
}

int			get_size(char *str, t_flags *flags)
{
	int		i;
	char	size[3];

	i = 0;
	while (ft_strichr(SIZE_C, str[i]) != -1 && i < 2 && str[i] != '\0')
	{
		size[i] = str[i];
		i++;
	}
	size[i] = 0;
	if (i == 0)
		return (0);
	if (ft_strcmp(size, "l") == 0)
		flags->size = LOW_L;
	else if (ft_strcmp(size, "ll") == 0)
		flags->size = LL;
	else if (ft_strcmp(size, "L") == 0)
		flags->size = UP_L;
	else if (ft_strcmp(size, "h") == 0)
		flags->size = H;
	else if (ft_strcmp(size, "hh") == 0)
		flags->size = HH;
	else
		ft_error();
	return (i);
}
