/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimaltofraction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:20:00 by idcornua          #+#    #+#             */
/*   Updated: 2019/01/17 12:43:35 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int  *ft_decimaltofraction(double nbr, int maxMagnitude) {
  int magnitude = 1;

  while (!ft_isInt(nbr) && magnitude < maxMagnitude) {
    nbr *= 10;
    magnitude *= 10;
  }

  static int result[2];
  result[0] = nbr;
  result[1] = magnitude;

  return result;
}