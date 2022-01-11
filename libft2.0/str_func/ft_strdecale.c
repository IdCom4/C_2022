/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdecale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:08:09 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/13 11:24:07 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdecale(char *str, int to_decale, int sens, int len)
{
	int i;

	if (!str)
		return (NULL);
	len = (len < 0) ? ft_strlen(str) : len;
	i = 0;
	if (sens < 0)
	{
		while (str[i + to_decale])
		{
			str[i] = str[i + to_decale];
			i++;
		}
	}
	else
	{
		while ((len - 1) - to_decale >= 0)
		{
			str[len - 1] = str[(len - 1) - to_decale];
			len--;
		}
	}
	str[((sens < 0) ? i : len - 1)] = ((sens < 0) ? 0 : -1);
	return (str);
}
