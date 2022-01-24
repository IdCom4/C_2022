/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getFileContentAsList.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:41:41 by idcornua          #+#    #+#             */
/*   Updated: 2019/07/12 14:27:25 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

# define BUFFER_SIZE 1200

int ft_getFileContentAsList(const char *fileName, linkedList **head) {
  int fd = 0;
  int totalNbrReadChars = 0;

  if ((fd = open(fileName, O_RDONLY)) <= 0)
		return -1;

  *head = NULL;
  linkedList *cursor = NULL;

  do {
  
    char *newChunk = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!newChunk) {
      ft_lstdel(head, &ft_del);
      return -1;
    }

    int nbrReadChars = read(fd, newChunk, BUFFER_SIZE);
    if (nbrReadChars <= 0) {
      free(newChunk);

      if (nbrReadChars < 0) return -1;
      else break;
    }

    newChunk[nbrReadChars] = '\0';
    
    linkedList *newLink = ft_lstnew(newChunk, nbrReadChars);
    if (!newLink) {
      free(newChunk);
      ft_lstdel(head, &ft_del);
      return -1;
    }

    ft_lstpush(head, &cursor, newLink);

    totalNbrReadChars += nbrReadChars;

  } while (TRUE);

  if (!totalNbrReadChars)
    return 0;
  
  return totalNbrReadChars; 
}