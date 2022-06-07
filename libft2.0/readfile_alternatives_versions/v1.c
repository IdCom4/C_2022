/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfileV1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:18:12 by idcornua          #+#    #+#             */
/*   Updated: 2019/07/12 14:43:19 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// v1 takes ~ 10 seconds to read 50 times a file of 9000 lines

#include "libft.h"

int		ft_readfileV1(const char *filename, char ***dest) {
	int		fd;
	int		nbrl = 0;
	int		ret;
	char	*line;
	char	**file_content = NULL;

	if ((fd = open(filename, O_RDONLY)) <= 0)
		return (-1);

	while ((ret = ft_getnextline(fd, &line)) > 0) {

		if (!(file_content = ft_reallocstrtab(file_content, nbrl, nbrl + 2))) {
			ft_freestrtabn(file_content, nbrl, TRUE);
			return (-1);
		}

		file_content[nbrl] = line;
		nbrl++;
	}

	if (ret == -1 && nbrl > 0) {
    ft_freestrtabn(file_content, nbrl, TRUE);
    file_content = NULL;
  }

	*dest = file_content;
	return (nbrl);
}