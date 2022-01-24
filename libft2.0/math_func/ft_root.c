/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_root.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 14:12:09 by idcornua          #+#    #+#             */
/*   Updated: 2019/01/02 14:17:13 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_root(nthRoot, nbr) = if (x ^ nthRoot == nbr) return x

double ft_root(int nthRoot, double nbr){
  double root = 2;
  double stepSize = 0.5;
  double powerResult = 0;
  

  // get root to less than 1 too high
  long long llPowerResult;
  while ((llPowerResult = ft_di_power(root, nthRoot)) < nbr && root < 46341)
    root++;
  
  if (llPowerResult == nbr)
    return llPowerResult;

  // means numbers are too high to be computed
  if (root >= 46341)
    return -1;

  root -= stepSize;

  while (stepSize >= MATH_PRECISION) {
		// an untested alternative could be to start root to 1.0 and to as follow:
		// root -= (ft_di_power(root, nthRoot) - nbr) / ( nthRoot * ft_di_power(root, (nthRoot - 1)) );

		stepSize *= 0.5;

		powerResult = ft_di_power(root, nthRoot);
		if (powerResult == nbr)
			return root;
		if (powerResult > nbr)
			root -= stepSize;
		else
			root += stepSize;
  }

  return root;
}
