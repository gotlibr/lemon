/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:04:44 by hlriabts          #+#    #+#             */
/*   Updated: 2018/01/28 16:11:24 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include "ft_printf.h"

t_desc				*find_line(t_desc **list, const int fd)
{
	t_desc *tmp;
	t_desc *buf;
	t_desc *new_list;

	buf = *list;
	while ((*list)->next != NULL)
	{
		if ((*list)->fd == fd)
		{
			tmp = *list;
			*list = buf;
			return (tmp);
		}
		*list = (*list)->next;
	}
	new_list = (t_desc*)malloc(sizeof(t_desc));
	new_list->buf = (char *)malloc((BUFF_SIZE + 1) * sizeof(char));
	ft_bzero(new_list->buf, (BUFF_SIZE + 1) * sizeof(char));
	new_list->fd = fd;
	new_list->ret = read(new_list->fd, new_list->buf, BUFF_SIZE);
	new_list->next = buf;
	new_list->tmp = new_list->buf;
	(*list) = new_list;
	return (new_list);
}

int					read_line(t_desc *current, char **line)
{
	if (current->ret == 0)
		return (0);
	if (*line)
		ft_bzero(*line, ft_strlen(*line) * sizeof(char));
	while (1)
	{
		if (ft_strchr(current->buf, '\n') != NULL)
		{
			current->buf[ft_strchr(current->buf, '\n') - current->buf] = '\0';
			if (!(*line = ft_join(line, current->buf)))
				return (-1);
			current->buf = ft_strchr(current->buf, '\0') + 1;
			return (1);
		}
		else if ((ft_strchr(current->buf, '\0') - current->buf) > 0)
			if (!(*line = ft_join(line, current->buf)))
				return (-1);
		current->buf = current->tmp;
		ft_bzero(current->buf, (BUFF_SIZE + 1) * sizeof(char));
		current->ret = read(current->fd, current->buf, BUFF_SIZE);
		if (current->ret == 0 && ft_strlen(*line) != 0)
			return (1);
		else if (current->ret == 0)
			return (0);
	}
}

int					get_next_line(const int fd, char **line)
{
	static t_desc	*list;
	char			buf;

	buf = '0';
	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (read(fd, &buf, 0) || !line)
		return (-1);
	*line = (char *)malloc((1 + 1) * sizeof(char));
	if (list == NULL)
	{
		list = (t_desc*)malloc(sizeof(t_desc));
		list->next = NULL;
	}
	return (read_line(find_line(&list, fd), line));
}
