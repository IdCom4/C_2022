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

char	*ft_char_replace(char *str, char toFind, char replaceBy)
{

	for (size_t i = 0; str[i] != '\0'; i++)
		if (str[i] == toFind) str[i] = replaceBy;

	return str;
}
