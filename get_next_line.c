/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:31:27 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/07 12:03:55 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_prlist	*ft_prlistnewstr(char *content, int fd, t_prlist *prev)
{
	t_prlist	*newlist;

	if (!(newlist = (t_prlist *)malloc(sizeof(t_prlist))))
		return (NULL);
	if (content == NULL)
	{
		newlist->content = NULL;
		fd = 0;
	}
	else
	{
		newlist->content = content;
		newlist->fd = fd;
	}
	newlist->prev = prev;
	newlist->next = NULL;
	return (newlist);
}

void		takeline(char *buf, char **line)
{
	int		i;
	size_t	size;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	*line = ft_strsub(buf, 0, i);
	size = ft_strlen(buf);
	ft_memmove(buf, buf + (i + 1), size - i);
	buf[size - i] = '\0';
}

void		ft_chooseid(t_prlist **id, const int fd)
{
	while ((*id)->prev)
		(*id) = (*id)->prev;
	while ((*id)->fd != fd && (*id)->next)
		(*id) = (*id)->next;
	if ((*id)->fd != fd)
	{
		(*id)->next = ft_prlistnewstr(ft_strnew(0), fd, (*id));
		(*id) = (*id)->next;
	}
}

int			get_next_line(const int fd, char **line)
{
	static t_prlist	*id;
	char			*buftmp;
	char			*todel;
	int				red;

	buftmp = ft_strnew(BUFF_SIZE + 1);
	if (!line || (read(fd, buftmp, 0) == -1))
		return (-1);
	id = !id ? ft_prlistnewstr(ft_strnew(0), fd, NULL) : id;
	if (id->fd != fd)
		ft_chooseid(&id, fd);
	while (!ft_strchr(id->content, '\n') &&\
	(red = read(id->fd, buftmp, BUFF_SIZE)))
	{
		buftmp[red] = '\0';
		todel = id->content;
		id->content = ft_strjoin(todel, buftmp);
		ft_strdel(&todel);
	}
	ft_strdel(&buftmp);
	if (red == 0 && !((char *)id->content)[0])
		return (0);
	takeline(id->content, line);
	return (1);
}
