/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:04:47 by hlriabts          #+#    #+#             */
/*   Updated: 2017/11/11 16:34:08 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		list_free(t_list **list)
{
	t_list *buf;

	buf = (t_list*)malloc(sizeof(t_list));
	while ((*list)->next)
	{
		buf = (*list)->next;
		free(*list);
		*list = buf;
	}
	free(list);
}

static void		list_cpy(t_list **dst, t_list *src)
{
	(*dst)->content = src->content;
	(*dst)->content_size = src->content_size;
	(*dst)->next = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *list_b;

	if (!lst || !f)
		return (NULL);
	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	list_cpy(&list, f(lst));
	list_b = list;
	while (lst->next)
	{
		if (!(list->next = (t_list*)malloc(sizeof(t_list))))
		{
			list_free(&list);
			return (NULL);
		}
		lst = lst->next;
		list = list->next;
		list_cpy(&list, f(lst));
	}
	return (list_b);
}
