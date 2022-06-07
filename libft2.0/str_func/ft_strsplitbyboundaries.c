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

  // if no list len has been provided,
  // get it
  if (!lstLen) {
    boundaryList *cursor = head;
    while (cursor) {
      lstLen++;
      cursor = cursor->next;
    }
  }

  // if list was empty or memory allocation failed, return with error code
  if (!lstLen || !(tab = (char **)malloc(sizeof(char *) * lstLen + 1)))
    return -1;
  

  size_t lineIndex = 0;
  // for each link
  while (head) {

    char *line = NULL;
    // copy the line
    // if the mem alloc failed, free what was already allocated by this function
    // and return with error code
    if (!(line = ft_strndup(&str[head->start], head->end - head->start))) {
      ft_freestrtabn(tab, lineIndex, TRUE);
      return -1;
    }

    // store the line
    tab[lineIndex] = line;

    // free the link if requested
    if (freeLst)
      ft_blstdelthis(&head, head);
    else
      head = head->next;
  }

  // null end the array
  tab[lstLen] = 0;
  *tabDest = tab;

  // and return the list len
  return lstLen;
}