/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:38:50 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/14 12:29:27 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_log(x) = if (r ^ n == x) return n

double  ft_log(unsigned int nbr) {
  if (nbr == 10)
    return 1;

  double  stepSize = 0.5;
  double  log = 1;

  if (nbr > 10) {
    unsigned int nb = nbr;
    while (nb > 10) {
      nb *= 0.1;
      log++;
    }
    if (nb == 10)
      return log;
  }

  log -= stepSize;

  // here we know that log is to high from less than 1
  while (stepSize >= MATH_PRECISION) {
    stepSize *= 0.5;

    double powerResult = ft_d_power(10, log);
    printf(" pr: %.20f\n", powerResult);
    printf(" log: %.20f\n", log);
    printf(" <: %d\n", powerResult < (double)nbr);

    if (powerResult == (double)nbr)
      return powerResult;
    else if (powerResult > (double)nbr)
      log -= stepSize;
    else
      log += stepSize;
  }

  return log;
}