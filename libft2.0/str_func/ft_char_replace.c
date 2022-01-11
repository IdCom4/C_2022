/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:45:52 by idcornua          #+#    #+#             */
/*   Updated: 2019/01/25 16:50:06 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_char_replace(char *str, char to_find, char replace_by)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
			str[i] = replace_by;
		i++;
	}
	return (str);
}
