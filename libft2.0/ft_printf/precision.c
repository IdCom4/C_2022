/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:10:41 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/12 16:24:30 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_retro_arr(char *value, int *n, int i, int neg)
{
	int rest;

	rest = 0;
	while (*n + i - 1 - neg >= 0 && (value[*n + i - 1] == '9'
	|| (value[*n + i - 1] == '.' && value[*n + i - 2] == '9')))
	{
		rest = 1;
		value[*n + i - ((value[*n + i - 1] == '.') ? 2 : 1)] = '0';
		i -= (value[*n + i - 1] == '.') ? 2 : 1;
	}
	if (*n + i - 1 - neg < 0)
	{
		if (neg)
			value = ft_strjoinfe("-1", ft_strndel(value, 1, 1), 1);
		else
			value = ft_strjoinfe("1", value, 1);
		*n = *n + 1;
	}
	else if (rest)
		value[*n + i - ((value[*n + i - 1] == '.') ? 2 : 1)] += 1;
	return (value);
}

char		*spec_arrondi(char *value, int nbr_digit, int *preci, int n)
{
	if (nbr_digit == 1 && value[n + 1] == '5' && (value[n - 1] - 48) % 2 == 0)
	{
		*preci = -1;
		value[n] = '\0';
	}
	return (value);
}

char		*ft_arrondi(char *value, int preci, int nbr_i, int n)
{
	int len;

	len = n + nbr_i + 1;
	value = spec_arrondi(value, nbr_i, &preci, n);
	if (preci >= 0)
	{
		if (value[n + preci + 1] >= '5')
		{
			if (value[n + preci] == '9')
				value = ft_retro_arr(value, &n, preci + 1, (value[0] == '-'));
			else
			{
				if (value[n + preci] == '.')
					value[n + preci - 1] += 1;
				else
					value[n + preci] += 1;
			}
		}
		value[n + preci + 1] = 0;
	}
	if (preci == 0)
		value[n] = 0;
	return (value);
}

char		*ft_decimal_preci(char *value, int n, int v_len)
{
	char	*fill;
	int		neg;

	neg = (value[0] == '-') ? 1 : 0;
	n = n + neg;
	if (n <= 0 && value[0] == '0')
		return (((value[0] = 0) == 0) ? value : value);
	if (n <= 0)
		return (value);
	if (neg)
	{
		fill = ft_strjoinfe("-", ft_strfill(ft_strnew(n), '0', n), 1);
		value = ft_strshift(value, 1, START, v_len);
	}
	else
		fill = ft_strfill(ft_strnew(n), '0', n);
	return (ft_strjoinfe(fill, value, 2));
}

char		*ft_precision(int precision, char type, char *value, int v_len)
{
	int		n;
	char	*fill;
	int		len;

	n = precision - v_len;
	if (type == 's' && v_len > precision)
		value[precision] = 0;
	else if (type != 'f' && type != 's')
		value = ft_decimal_preci(value, n, v_len);
	else if (type == 'f' && ft_strichr(value, 'n') == -1)
	{
		n = ft_strichr(value, '.');
		len = (n != -1) ? v_len - (n + 1) : 0;
		if (len < precision)
		{
			fill = ft_strfill(ft_strnew(precision - len), '0', precision - len);
			if (n == -1)
				value = ft_strjoinfe(value, ".", 0);
			value = ft_strjoinfe(value, fill, 2);
		}
		else if (len > precision)
			value = ft_arrondi(value, precision, len, n);
	}
	return (value);
}
