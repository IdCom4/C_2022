/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:32:27 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/14 12:53:53 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_error(void)
{
	exit(EXIT_FAILURE);
	return (666);
}

char	*ft_strjoinfe(char *s1, char *s2, int to_free)
{
	if (!(s1 = ft_strjoinf(s1, s2, to_free)))
		ft_error();
	return (s1);
}

char	*ft_strnjoinfe(char *s1, char *s2, size_t n, int to_free)
{
	if (!(s1 = ft_strnjoinf(s1, s2, n, to_free)))
		ft_error();
	return (s1);
}

char	*ft_strndupe(char *str, size_t n)
{
	if (!(str = ft_strndup(str, n)))
		ft_error();
	return (str);
}

char	*ft_strdupe(char *str)
{
	char *new;

	if (!(new = ft_strdup(str)))
		ft_error();
	return (new);
}
