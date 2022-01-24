/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfileV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:18:12 by idcornua          #+#    #+#             */
/*   Updated: 2019/07/12 14:43:19 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// v3 takes ~ 0.7 seconds to read 50 times a file of 9000 lines

// but it takes a very big buffer size to achieve it,
// and do not take into account the empty lines

#include "libft.h"

# define BUFFER_SIZE 1250000

int ft_readfileV3(const char *fileName, char ***fileContentDest) {

  int fd = 0;
  int totalNbrReadChars = 0;

  char *fileContent = NULL;
  char fileBuffer[BUFFER_SIZE + 1];

  if ((fd = open(fileName, O_RDONLY)) <= 0)
		return -1;

  do {
    
    int nbrReadChars = read(fd, fileBuffer, BUFFER_SIZE);

    if (nbrReadChars < 0) {
      if (fileContent) free(fileContent);

      return -1;
    }
    else if (nbrReadChars == 0)
      break;

    totalNbrReadChars += nbrReadChars;

    if (fileContent)
      fileContent = ft_strjoinf(fileContent, fileBuffer, FIRST);
    else
      fileContent = ft_strdup(fileBuffer);

  } while (TRUE);

  if (!fileContent)
    return 0;

  char **tab = NULL;
  if (!(tab = ft_strsplit(fileContent, "\r\n"))) {
    free(fileContent);
    return -1;
  }

  *fileContentDest = tab;

  return totalNbrReadChars;
}