/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:56:02 by idcornua          #+#    #+#             */
/*   Updated: 2019/06/25 11:02:07 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  ft_countwords(char const *str, char delimiter) {
  int nbrWords = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    while (str[i] == delimiter)
      i++;

    if (str[i] == '\0')
      return nbrWords;
    
    nbrWords++;

    while (str[i] != delimiter && str[i] != '\0')
      i++;
  }

  return nbrWords;
}

char			**ft_strsplit(char const *str, char delimiter) {

  char **tab = NULL;
  int totalNbrWords = 0;
  int wordStartIndex = 0;
  int i = 0;

  if (!str || delimiter == '\0')
    return NULL;
  if (!(totalNbrWords = ft_countwords(str, delimiter)) || !(tab = (char **)malloc(sizeof(char *) * totalNbrWords + 1)))
    return NULL;

  for (int nbrSplitedWords = 0; nbrSplitedWords < totalNbrWords; nbrSplitedWords++) {

    while (str[i] == delimiter)
      i++;
    
    wordStartIndex = i;
    while(str[i] != delimiter && str[i] != '\0')
      i++;

    if (wordStartIndex == i)
      break;
    
    if (!(tab[nbrSplitedWords] = ft_strndup(&str[wordStartIndex], i - wordStartIndex))) {
      ft_freestrtabn(tab, nbrSplitedWords, TRUE);
      return NULL;
    }
    
  }

  tab[totalNbrWords] = 0;

  return tab;
}