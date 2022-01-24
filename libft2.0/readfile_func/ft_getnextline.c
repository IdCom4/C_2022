/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:41:41 by idcornua          #+#    #+#             */
/*   Updated: 2019/07/12 14:27:25 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# define BUFFER_SIZE 300

int  ft_getnextline(int fd, char **newLine) {
  static char lineBuffer[BUFFER_SIZE + 1] = "";

  char *tmp = NULL;

  size_t lineLen = 0;
  int nbrReadChars = 0;
  int newLineIndex = 0;
  
  do {
    if (lineBuffer[0] == '\0') {
      nbrReadChars = read(fd, lineBuffer, BUFFER_SIZE);
  
      if (nbrReadChars <= 0) {
        if (nbrReadChars < 0 && *newLine) free(*newLine);
        else if (nbrReadChars == 0) *newLine = NULL;
        return nbrReadChars;
      }

      lineBuffer[nbrReadChars] = '\0';
    }
    else
      nbrReadChars = ft_strlen(lineBuffer);
          
    newLineIndex = ft_strcharschr(lineBuffer, "\r\n");

    lineLen += newLineIndex >= 0 ? newLineIndex : nbrReadChars;
    
    if (*newLine)
      tmp = *newLine;

    if (!tmp)
      *newLine = ft_strndup(lineBuffer, newLineIndex < 0 ? nbrReadChars : newLineIndex);
    else
      *newLine = ft_strnjoinf(tmp, lineBuffer, newLineIndex < 0 ? nbrReadChars : newLineIndex, FIRST);
    
    if (!*newLine) {
      if (tmp) free(tmp);
      return -1;
    }

    if (newLineIndex < 0)
      lineBuffer[0] = '\0';

  } while (newLineIndex < 0);

  if (lineBuffer[newLineIndex] == '\r' && lineBuffer[newLineIndex + 1] == '\n')
    newLineIndex++;

  ft_strcpy(lineBuffer, &lineBuffer[newLineIndex + 1]);
  
  return lineLen;
}
