/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:09:34 by idcornua          #+#    #+#             */
/*   Updated: 2019/01/24 18:56:39 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_d(int size, va_list ap)
{
	long long result;

	if (size == UNSET || size == LOW_L)
		result = (size == UNSET) ? va_arg(ap, int) : va_arg(ap, long);
	else if (size == LL || size == H)
		result = (size == LL) ? va_arg(ap, long long) : (short)va_arg(ap, int);
	else
		result = (char)va_arg(ap, int);
	return (ft_lltoa(result));
}

char	*ft_o(int size, va_list ap)
{
	unsigned long long result;

	if (size == UNSET || size == LOW_L)
		result = (size == UNSET) ? va_arg(ap, unsigned int)
			: va_arg(ap, unsigned long);
	else if (size == LL || size == H)
		result = (size == LL) ? va_arg(ap, unsigned long long)
			: (unsigned short)va_arg(ap, unsigned int);
	else
		result = (unsigned char)va_arg(ap, unsigned int);
	return (ft_from_base_10_ull(result, "01234567", 8));
}

char	*ft_u(int size, va_list ap)
{
	unsigned long long result;

	if (size == UNSET || size == LOW_L)
		result = (size == UNSET) ? va_arg(ap, unsigned int)
			: va_arg(ap, unsigned long);
	else if (size == LL || size == H)
		result = (size == LL) ? va_arg(ap, unsigned long long)
			: (unsigned short)va_arg(ap, unsigned int);
	else
		result = (unsigned char)va_arg(ap, unsigned int);
	return (ft_ulltoa(result));
}

char	*ft_x(int size, va_list ap)
{
	unsigned long long result;

	if (size == UNSET || size == LOW_L)
		result = (size == UNSET) ? va_arg(ap, unsigned int)
			: va_arg(ap, unsigned long);
	else if (size == LL || size == H)
		result = (size == LL) ? va_arg(ap, unsigned long long)
			: (unsigned short)va_arg(ap, unsigned int);
	else
		result = (unsigned char)va_arg(ap, unsigned int);
	return (ft_from_base_10_ull(result, "0123456789abcdef", 16));
}

char	*ft_gx(int size, va_list ap)
{
	unsigned long long result;

	if (size == UNSET || size == LOW_L)
		result = (size == UNSET) ? va_arg(ap, unsigned int)
			: va_arg(ap, unsigned long);
	else if (size == LL || size == H)
		result = (size == LL) ? va_arg(ap, unsigned long long)
			: (unsigned short)va_arg(ap, unsigned int);
	else
		result = (unsigned char)va_arg(ap, unsigned int);
	return (ft_from_base_10_ull(result, "0123456789ABCDEF", 16));
}
