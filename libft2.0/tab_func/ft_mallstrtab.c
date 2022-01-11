/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallstrtab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:12:02 by idcornua          #+#    #+#             */
/*   Updated: 2019/02/11 10:59:51 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **tab, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	return (NULL);
}

void		*ft_mallstrtab(size_t tab_size, size_t str_size)
{
	char		**tab;
	size_t		i;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * tab_size)))
		return (NULL);
	while (i < tab_size)
	{
		if (str_size > 0)
		{
			if (!(tab[i] = ft_strnew(str_size)))
				return (ft_free(tab, i));
		}
		else
			tab[i] = NULL;
		i++;
	}
	return (tab);
}
