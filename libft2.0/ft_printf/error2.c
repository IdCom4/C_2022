/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:16:54 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/14 10:04:38 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdupfe(char *to_dup, char *to_free)
{
	char *to_return;

	if (!(to_return = ft_strdupf(to_dup, to_free)))
		ft_error();
	return (to_return);
}

char	*ft_strcjoinfe(char *s1, char *s2, char c, int to_free)
{
	char *to_return;

	if (!(to_return = ft_strcjoinf(s1, s2, c, to_free)))
		ft_error();
	return (to_return);
}

char	*ft_strjoine(char *s1, char *s2)
{
	if (!(s1 = ft_strjoin(s1, s2)))
		ft_error();
	return (s1);
}
