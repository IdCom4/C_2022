/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:18:12 by idcornua          #+#    #+#             */
/*   Updated: 2019/07/12 14:43:19 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_readfile(char *filename, char ***dest)
{
	int		fd;
	int		nbrl;
	int		ret;
	char	*line;
	char	**file_content;

	if ((fd = open(filename, O_RDONLY)) <= 0)
		return (-1);
	nbrl = 0;
	file_content = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(file_content = ft_reallocstrtab(file_content, nbrl, nbrl + 2)))
		{
			ft_freestrtabn(file_content, nbrl, TRUE);
			return (-1);
		}
		file_content[nbrl] = line;
		nbrl++;
	}
	if (ret == -1 && nbrl > 0)
		file_content = ft_freestrtabn(file_content, nbrl, TRUE);
	*dest = file_content;
	return (nbrl);
}
