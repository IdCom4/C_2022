/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_n_to_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:13:01 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/12 16:56:41 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_base_n_to_x(char *nbr, char *baseFrom, char *baseTo)
{
	int baseFromLen = ft_strlen(baseFrom);
	int baseToLen = ft_strlen(baseTo);

	return (ft_from_base_10(ft_to_base_10(nbr, baseFrom, baseFromLen), baseTo, baseToLen));
}
