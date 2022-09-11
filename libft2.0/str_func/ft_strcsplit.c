/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcsplit.c                                     :+:      :+:    :+:   */
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

char			**ft_strcsplit(const char *str, const unsigned char delimiter) {

  char **tab = NULL;
  int totalNbrWords = 0;
  int wordStartIndex = 0;
  int i = 0;

  // if there is no str nor delimiter, return NULL
  if (!str || delimiter == '\0')
    return NULL;
  
  // if there is no words to split or the mem alloc failed, return NULL
  if (!(totalNbrWords = ft_countwords(str, delimiter)) || !(tab = (char **)malloc(sizeof(char *) * totalNbrWords + 1)))
    return NULL;

  // while we didn't split every word
  for (int nbrSplitedWords = 0; nbrSplitedWords < totalNbrWords; nbrSplitedWords++) {

    // go to the delimiter
    while (str[i] == delimiter)
      i++;
    
    // store the starting index of the word
    wordStartIndex = i;
    // and go to its ending index
    while(str[i] != delimiter && str[i] != '\0')
      i++;

    // if its the same, break the loop
    if (wordStartIndex == i)
      break;
    
    // if the dup mem alloc fail, free what's already allocated and return NULL
    if (!(tab[nbrSplitedWords] = ft_strndup(&str[wordStartIndex], i - wordStartIndex))) {
      ft_freestrtabn(tab, nbrSplitedWords, TRUE);
      return NULL;
    }
    
  }

  // NULL end the array
  tab[totalNbrWords] = NULL;

  // and return it
  return tab;
}