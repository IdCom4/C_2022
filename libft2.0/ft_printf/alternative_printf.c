/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternative_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:20:07 by idcornua          #+#    #+#             */
/*   Updated: 2019/04/16 17:25:11 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sprintf(char **dest, char const *format, ...)
{
	t_flags	*flags;
	va_list	ap;
	int		len;

	flags = NULL;
	if (!format || !(*dest = ft_strnew(0)))
		ft_error();
	ft_parse_format(format, &flags);
	va_start(ap, format);
	ft_algo((char *)format, dest, flags, ap);
	len = ft_strlen(*dest);
	ft_char_replace(*dest, -1, 0);
	ft_freeflags(&flags);
	va_end(ap);
	return (len);
}

int		ft_fdprintf(int fd, char const *format, ...)
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
	write(fd, to_print, len);
	free(to_print);
	ft_freeflags(&flags);
	va_end(ap);
	return (len);
}
