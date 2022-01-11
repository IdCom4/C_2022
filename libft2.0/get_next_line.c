/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:41:41 by idcornua          #+#    #+#             */
/*   Updated: 2019/07/12 14:27:25 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_line(t_list **head, t_list *cursor, char **dest, int rl)
{
	int len;

	len = ft_strichr(cursor->content, '\n');
	len = (len < 0) ? ft_strlen(cursor->content) : len;
	if (!(*dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	ft_strccpy(*dest, cursor->content, '\n');
	if (rl == 0 && ft_strlen(cursor->content) == 0)
	{
		ft_strdel(dest);
		ft_lstdelthis(head, cursor);
		return (0);
	}
	else
	{
		cursor->content = ft_strchrf(cursor->content, '\n');
		if (cursor->content)
			cursor->content = ft_strndel(cursor->content, 1, 1);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list		*head;
	t_list				*cursor;
	char				buff[BUFF_SIZE + 1];
	int					rl;

	if (fd < 0 || read(fd, buff, 0) < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!(cursor = ft_lstfindor(head, fd, NULL)))
	{
		cursor = ft_lstnew(NULL, 0);
		if (!cursor)
			return (-1);
		cursor->content_size = fd;
		ft_lstadd(&head, cursor);
	}
	rl = -1;
	while (!ft_strchr(cursor->content, '\n') && rl != 0)
	{
		rl = read(fd, buff, BUFF_SIZE);
		buff[rl] = '\0';
		if (!(cursor->content = ft_strjoinf(cursor->content, buff, 0)))
			cursor->content = ft_strdup(buff);
		ft_strclr(buff);
	}
	return (get_line(&head, cursor, line, rl));
}
