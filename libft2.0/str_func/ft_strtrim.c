/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:23:37 by idcornua          #+#    #+#             */
/*   Updated: 2019/06/25 11:03:21 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trim;
	int		i;
	int		n;

	if (!s)
		return (NULL);
	trim = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!trim)
		return (NULL);
	n = 0;
	i = 0;
	while (s[n] == ' ' || s[n] == '\n' || s[n] == '\t')
		n++;
	while (s[n] != '\0')
		trim[i++] = s[n++];
	trim[i] = '\0';
	if (i <= 0)
		return (trim);
	while ((trim[i] == ' ' || trim[i] == '\n'
	|| trim[i] == '\t' || trim[i] == '\0') && i > 0)
		i--;
	trim[i + 1] = '\0';
	return (trim);
}
