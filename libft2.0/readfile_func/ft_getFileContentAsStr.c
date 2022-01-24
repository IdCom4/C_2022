/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getFileContentAsStr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:41:41 by idcornua          #+#    #+#             */
/*   Updated: 2019/07/12 14:27:25 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

# define BUFFER_SIZE 1200

int         ft_getFileContentAsStr(const char *fileName, char **fileContent) {

  linkedList *head = NULL;

  int fileLength = ft_getFileContentAsList(fileName, &head);

  if (fileLength <= 0)
    return fileLength;

  if (!(*fileContent = (char *)malloc(sizeof(char) * fileLength + 1))) {
    ft_lstdel(&head, &ft_del);
    return -1;
  }

  size_t i = 0;
  while (head) {
    for (size_t j = 0; j < head->contentSize; j++)
      *fileContent[i++] = ((char *)head->content)[j];
      
    linkedList *next = head->next;
    ft_lstdelone(&head, &ft_del);
    head = next;
  }

  *fileContent[i] = '\0';

  return fileLength;
}