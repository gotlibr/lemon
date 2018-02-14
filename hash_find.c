/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 20:58:15 by hlriabts          #+#    #+#             */
/*   Updated: 2018/02/13 20:59:30 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void free_rooms(t_rooms **list)
{
	t_rooms *tmp;
	t_links *tmp2;
	while(*list)
	{
		if ((*list)->name)
			free((*list)->name);
		while ((*list)->trans)
		{
			tmp2 = (*list)->trans->next;
			if ((*list)->trans)
				free ((*list)->trans);
			(*list)->trans = tmp2;
		}
		tmp = (*list)->next;
		if (*list)
			free(*list);
		(*list) = tmp;
	}
}

t_rooms *copy_list(t_rooms *list)
{

	t_rooms *room;

	room = (t_rooms *)ft_memalloc(sizeof(t_rooms));
	if (list)
		room->name = ft_strdup(list->name);
	else
		return(NULL);
	room->x = list->x;
	room->y = list->y;
	room->ant_n = -2;
	room->dist = INT_MAX;
	room->next = NULL;
	room->trans = NULL;
	return(room);
}

t_rooms *copy_list_2(t_rooms *list)
{

	t_rooms *room;

	room = (t_rooms *)ft_memalloc(sizeof(t_rooms));
	if (list)
		room->name = ft_strdup(list->name);
	else
		return(NULL);
	room->x = list->x;
	room->y = list->y;
	room->ant_n = 0;
	room->dist = INT_MAX;
	room->next = NULL;
	room->trans = NULL;
	return(room);
}

t_rooms **create_table (t_rooms *list)
{
	t_rooms **arr;
	int i;
	t_rooms *tmp;

	i = 0;
	arr = (t_rooms **)ft_memalloc(sizeof(t_rooms *) * g_count);
	while (list)
	{
		if (arr[get_key(list->name)])
		{
			tmp = copy_list(list);
			tmp->next = arr[get_key(list->name)];
			arr[get_key(list->name)] = tmp;
		}
		else
			arr[get_key(list->name)] = 	copy_list(list);	
		list = list->next;
	}
	return (arr);
}

int get_key(char *name)
{
	int i;
	int key;

	key = 0;
	i = 0;
	while (i < (int)ft_strlen(name))
	{
		key += name[i];
		i++;
	}
	key /= i;
	key = ABS((key  % (i + 10) ) % g_count);
	return(key);
}

t_rooms *hash_find_cell(t_rooms **hash, char *str)
{
	t_rooms *room;
	t_rooms *ret;
	t_rooms *room_tmp;

	room = hash[get_key(str)];
	room_tmp = room;
	while (room && !ft_strequ(str, room->name))
		room = room->next;
	if (room && ft_strequ(str, room->name))
	{
		ret = room;
		room = room_tmp;
		return(ret);
	}
	else
		error();
	return (NULL);
}