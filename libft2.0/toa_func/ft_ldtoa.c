/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:56:47 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/14 12:30:19 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ldtoa(long double nbr)
{
	// check for NaN
	if (!(nbr == nbr))
		return (ft_strdup("NaN"));
	
	// check for inf
	if (nbr == -1.0 / 0.0 || nbr == 1.0 / 0.0)
		return (ft_strdup((nbr == -1.0 / 0.0) ? "-inf" : "inf"));
	
	// check for -0
	if (1.0 / nbr == -1.0 / 0.0)
		return (ft_strdup("-0"));

	char					*str = NULL;

	// get integer part
	long long			exp = (long long)nbr;
	// and the decimal part
	long double		mantisse = nbr - exp;
	
	// make it positive if needed
	mantisse = (mantisse < 0) ? -mantisse : mantisse;

	// if parsing of integer part failed, return NULL
	if (!(str = ft_lltoa(exp)))
		return (NULL);
	
	// if there is a decimal part, join the dot and return NULL if failure
	if (mantisse && !(str = ft_strjoinf(str, ".", FIRST)))
		return (NULL);

	const unsigned long long maxIntMantisse = LLONG_MAX / 10;
	while (mantisse) {

		// get the max amount of mantisse number as int
		// to join them to the rest with a min amount of strjoinf calls
		unsigned long long intMantisse = 0; 
		while (mantisse && intMantisse < maxIntMantisse) {
			// get the next mantisse number as int
			const int nextMantisseNumber = (int)(mantisse * 10);
			
			// add it to thos we already got
			intMantisse *= 10;
			intMantisse += nextMantisseNumber;

			// remove it from those remaining
			mantisse = (mantisse * 10) - nextMantisseNumber;
		}

		// join that part of the mantisse to the rest, and return NULL if failure
		if (!(str = ft_strjoinf(str, ft_itoa(intMantisse), ALL)))
			return (NULL);
		
	}

	// return the full string
	return (str);
}
