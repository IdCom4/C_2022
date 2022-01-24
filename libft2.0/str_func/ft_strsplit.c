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

static linkedList *ft_storewordinnewlink(const char *str, size_t begin, size_t end) {
  char *newWord = NULL;
  size_t newWordLen = end - begin;
  linkedList *newLink = NULL;

  if (!(newWord = ft_strndup(&str[begin], newWordLen)) || !(newLink = ft_lstnew(newWord, newWordLen)) ) {
    if (newWord) free(newWord);
    return NULL;
  }

  return newLink;
}

static size_t     ft_getnextdelimiterIndex(const char *str, char *delimiters, size_t i) {
  while (str[i] != '\0' && ft_strichr(delimiters, str[i]) >= 0)
      i++;

  return i;
}

static size_t     ft_getnextnondelimiterIndex(const char *str, char *delimiters, size_t i) {
  while (str[i] != '\0' && ft_strichr(delimiters, str[i]) < 0)
      i++;

  return i;
}

char              **ft_strsplit(char const *str, char *delimiters) {
  if (!str || !delimiters)
    return NULL;

  linkedList *head = NULL;
  linkedList *cursor = NULL;
  size_t totalNbrWords = 0;

  for (size_t i = 0; str[i] != '\0';) {
    i = ft_getnextdelimiterIndex(str, delimiters, i);
    
    if (str[i] == '\0')
      break;

    totalNbrWords++;

    size_t wordStartIndex = i;
    i = ft_getnextnondelimiterIndex(str, delimiters, i);

    linkedList *newLink = NULL;

    if (!(newLink = ft_storewordinnewlink(str, wordStartIndex, i))) {
      ft_lstdel(&head, &ft_del);
      return NULL;
    }

    ft_lstpush(&head, &cursor, newLink);
  }

  if (totalNbrWords <= 0)
    return NULL;

  char **tab = NULL;
  if (!(tab = (char **)malloc(sizeof(char *) * totalNbrWords + 1))) {
    ft_lstdel(&head, &ft_del);
    return NULL;
  }

  cursor = head;

  for (size_t i = 0; i < totalNbrWords; i++) {
    tab[i] = (char *)cursor->content;
    cursor = cursor->next;
  }

  tab[totalNbrWords] = 0;

  ft_lstdel(&head, &ft_dummydel);

  return tab;
}
