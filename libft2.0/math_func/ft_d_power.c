/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_power.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:20:00 by idcornua          #+#    #+#             */
/*   Updated: 2019/01/17 12:43:35 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double ft_d_power(double nbr, double power) {
  if (ft_isInt(power)) {
    return ft_di_power(nbr, power);
  }
  
  int     powerInt = (int)power;
  double  powerRest = power - powerInt;

  int *fraction = ft_decimaltofraction(powerRest, 10);

  return  ft_di_power(nbr, powerInt) * ft_root(fraction[1], ft_di_power(nbr, fraction[0])); 

}
