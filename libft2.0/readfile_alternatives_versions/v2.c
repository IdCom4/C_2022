/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfileV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:18:12 by idcornua          #+#    #+#             */
/*   Updated: 2019/07/12 14:43:19 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// v2 takes ~ 1.9 seconds to read 50 times a file of 9000 lines

#include "libft.h"

int ft_readfileV2(const char *fileName, char ***fileContentDest) {

  int fd = 0;
  int lineLen = 0;
  size_t nbrLine = 0;

  linkedList *head = NULL;
  linkedList *cursor = NULL;

  if ((fd = open(fileName, O_RDONLY)) <= 0)
		return -1;

  cursor = head;
  while (lineLen > 0) {
    char *newLine = NULL;
    lineLen = ft_getnextline(fd, &newLine);
	
    if (lineLen < 0) {
      ft_lstdel(&head, &ft_del);
      close(fd);
      return -1;
    }
    else if (lineLen == 0 && !newLine) // endOfFile
      break;

    linkedList *newLink = ft_lstnew(newLine, 0);
    if (!newLink) {
      free(newLine);
      if (head)
        ft_lstdel(&head, &ft_del);
      
      
      close(fd);
      return -1;
    }

    if (!head)
      head = newLink;
    else 
      cursor->next = newLink;

    cursor = newLink;
    nbrLine++;
  }

  close(fd);

  if (nbrLine == 0 || lineLen < 0) {
    *fileContentDest = NULL;
    return lineLen < 0 ? lineLen : 0;
  }

  char **tab = NULL;
  if (!(tab = (char **)malloc(sizeof(char *) * nbrLine + 1))) {
    ft_lstdel(&head, &ft_del);
    return -1;
  }

  for (size_t i = 0; i < nbrLine; i++) {
    tab[i] = (char *)head->content;
    
    linkedList *newHead = head->next;
    free(head);
    head = newHead;
    
  }

  tab[nbrLine] = 0;
  *fileContentDest = tab;

  return nbrLine;
}