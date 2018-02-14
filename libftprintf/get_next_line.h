/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:04:47 by hlriabts          #+#    #+#             */
/*   Updated: 2017/12/14 18:57:45 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

typedef struct			s_desc_list
{
	int					fd;
	char				*buf;
	struct s_desc_list	*next;
	int					ret;
	char				*tmp;
}						t_desc;

int						get_next_line(const int fd, char **line);
#endif
