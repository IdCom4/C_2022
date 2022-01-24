/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitbyboundaries.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:56:02 by idcornua          #+#    #+#             */
/*   Updated: 2019/06/25 10:51:37 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strsplitbyboundaries(char ***tabDest, const char *str, boundaryList *head, size_t lstLen, t_bool freeLst) {
  char **tab = NULL;

  if (!lstLen) {
    boundaryList *cursor = head;
    while (cursor) {
      lstLen++;
      cursor = cursor->next;
    }
  }

  if (!lstLen || !(tab = (char **)malloc(sizeof(char *) * lstLen + 1)))
    return -1;
  

  size_t lineIndex = 0;
  while (head) {
    char *line = NULL;
    if (!(line = ft_strndup(&str[head->start], head->end - head->start))) {
      ft_freestrtabn(tab, lineIndex, TRUE);
      return -1;
    }

    tab[lineIndex] = line;

    if (freeLst)
      ft_blstdelthis(&head, head);
    else
      head = head->next;
  }

  tab[lstLen] = 0;
  *tabDest = tab;
  return lstLen;
}