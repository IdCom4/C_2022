/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:18:12 by idcornua          #+#    #+#             */
/*   Updated: 2019/07/12 14:43:19 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this is readfile V4
// v4 takes ~ 0.48 seconds to read 50 times a file of 9000 lines

#include "libft.h"

# define BUFFER_SIZE 1200

int ft_readfile(const char *fileName, char ***fileContentDest) {

  linkedList *head = NULL;

  // get the file content as chunks stored in a chained list
  // to find what we look for w/o extra steps
  int fileLength = ft_getFileContentAsList(fileName, &head);

  if (fileLength <= 0)
    return fileLength;

  char *fileContent = (char *)malloc(sizeof(char) * fileLength + 1);
  if (!fileContent) {
    ft_lstdel(&head, &ft_del);
    return -1;
  }

  boundaryList *blHead = NULL;
  boundaryList *blCursor = NULL;
  boundaryList *newBlLink = NULL;

  size_t i = 0;
  size_t nbrLine = 0;

  // iterate through the list, copy the result into a single string
  // and create a boundary list containing the limits of every line
  while (head) {
    for (size_t j = 0; j < head->contentSize; j++) {
      if (!newBlLink) {
        if (!(newBlLink = (boundaryList *)malloc(sizeof(boundaryList)))) {
          free(fileContent);
          ft_lstdel(&head, &ft_del);
          ft_blstdel(&blHead);
          return -1;
        }

        newBlLink->start = i;
        nbrLine++;
      }
      if (((char *)head->content)[j] == '\n' && newBlLink) { // end of line
        newBlLink->end = i;
        newBlLink->next = NULL;

        ft_blstpush(&blHead, &blCursor, newBlLink);
        newBlLink = NULL;
      }
      else if (((char *)head->content)[j] == '\r') {
        // if true, means line end in the same link
        if (j < head->contentSize - 1 && ((char *)head->content)[j + 1] == '\n')
          continue;
        // else means line end across 2 links
        else if (j == head->contentSize - 1 && (!head->next || ((char *)head->next->content)[0] == '\n'))
          break;
      }
  
      fileContent[i++] = ((char *)head->content)[j];
    }
      
    
    linkedList *next = head->next;
    ft_lstdelone(&head, &ft_del);
    head = next;
  }

  // in case the current new boundary link is not closed yet
  if (newBlLink) {
    newBlLink->end = i;
    newBlLink->next = NULL;
    ft_blstpush(&blHead, &blCursor, newBlLink);
  }
  
  fileContent[i] = '\0';

  char **tab = NULL;

  // we use the boundary list to split the file content where we want
  if (ft_strsplitbyboundaries(&tab, fileContent, blHead, nbrLine, TRUE) < 0) {
    free(fileContent);
    ft_blstdel(&blHead);
    return -1;
  }

  *fileContentDest = tab;

  return nbrLine;
}