/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 13:56:27 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/14 13:59:48 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	**get_colorlist(void)
{
	char **tab;
	char *strcolors;

	strcolors = ft_strjoine("", COLORS1);
	strcolors = ft_strjoinfe(strcolors, COLORS2, 0);
	strcolors = ft_strjoinfe(strcolors, COLORS3, 0);
	strcolors = ft_strjoinfe(strcolors, COLORS4, 0);
	strcolors = ft_strjoinfe(strcolors, COLORS5, 0);
	tab = ft_strsplit(strcolors, ' ');
	free(strcolors);
	return (tab);
}

static char	**get_colorcode(void)
{
	char **tab;
	char *strcolorcodes;

	strcolorcodes = ft_strjoine("", COLOR_CODES1);
	strcolorcodes = ft_strjoinfe(strcolorcodes, COLOR_CODES2, 0);
	strcolorcodes = ft_strjoinfe(strcolorcodes, COLOR_CODES3, 0);
	strcolorcodes = ft_strjoinfe(strcolorcodes, COLOR_CODES4, 0);
	strcolorcodes = ft_strjoinfe(strcolorcodes, COLOR_CODES5, 0);
	strcolorcodes = ft_strjoinfe(strcolorcodes, COLOR_CODES6, 0);
	tab = ft_strsplit(strcolorcodes, ' ');
	free(strcolorcodes);
	return (tab);
}

t_flags		*get_color(t_flags *flags, char *str)
{
	char	**colors;
	int		i;
	int		close;

	if ((close = ft_strichr(str, '}')) == -1
	|| !(colors = get_colorlist()))
		ft_error();
	i = 0;
	flags->color = TRUE;
	while (i < NBR_COLORS)
	{
		if (ft_strncmp(str, colors[i], close) == 0)
		{
			flags->color_index = i;
			flags->option_len = close + 1;
			ft_freestrtabn(colors, NBR_COLORS, TRUE);
			return (flags);
		}
		i++;
	}
	ft_error();
	return (NULL);
}

char		*get_color_code(t_flags *cursor)
{
	char	**color_codes;
	char	*result;

	if (!(color_codes = get_colorcode()))
		ft_error();
	result = ft_strdupe(color_codes[cursor->color_index]);
	ft_freestrtabn(color_codes, NBR_COLORS, TRUE);
	return (result);
}
