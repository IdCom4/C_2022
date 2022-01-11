/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:59:13 by idcornua          #+#    #+#             */
/*   Updated: 2019/01/17 14:07:13 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str) {
	int		start = 0;
	int		end = ft_strlen(str) - 1;
	char	tmp;

	while (start < end) {
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;

		start++;
		end--;
	}

	return (str);
}
