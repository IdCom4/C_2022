/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_n_to_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:13:01 by idcornua          #+#    #+#             */
/*   Updated: 2019/01/21 12:10:17 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_base_n_to_x_ull(char *nbr, char *baseFrom, char *baseTo)
{
	int baseFromLen = ft_strlen(baseFrom);
	int baseToLen = ft_strlen(baseTo);

	return (ft_from_base_10_ull(ft_to_base_10_ull(nbr, baseFrom, baseFromLen), baseTo, baseToLen));
}
