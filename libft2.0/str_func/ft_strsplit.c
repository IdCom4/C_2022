/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:56:02 by idcornua          #+#    #+#             */
/*   Updated: 2019/06/25 10:51:37 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbrwords(char const *s, char *charset)
{
	int		nbr_word;
	int		i;

	nbr_word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] && ft_strichr(charset, s[i]) != -1)
			i++;
		if (s[i] != '\0')
			nbr_word++;
		while (s[i] && ft_strichr(charset, s[1]) == -1)
			i++;
	}
	return (nbr_word);
}

static char		*ft_newword(char const *s, char *charset)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] && ft_strichr(charset, s[i]) == -1)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && ft_strichr(charset, s[i]))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char		**ft_nullendtab(char **tab, int index)
{
	tab[index] = 0;
	return (tab);
}

static int		ft_test_and_set(int *n, int *i, char const *s, char *charset)
{
	if (!s || !charset)
		return (0);
	*n = 0;
	*i = 0;
	return (1);
}

char			**ft_strsplit(char const *s, char *chars)
{
	char	**tab;
	int		index_w;
	int		i;

	if (ft_test_and_set(&i, &index_w, s, chars) == 0)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_nbrwords(s, chars) + 1))))
		return (NULL);
	if (ft_nbrwords(s, chars) == 0)
		return (ft_nullendtab(tab, 0));
	while (s[i] != '\0')
	{
		while (s[i] && ft_strichr(chars, s[i]) != -1)
			i++;
		if (s[i] != '\0')
		{
			if (!(tab[index_w] = ft_newword((char*)(&s[i]), chars)))
				return (ft_freestrtabn(tab, index_w, TRUE));
			index_w++;
		}
		while (s[i] && ft_strichr(chars, s[i]) == -1)
			i++;
	}
	return (ft_nullendtab(tab, index_w));
}
