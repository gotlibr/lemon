/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_alg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 21:01:03 by hlriabts          #+#    #+#             */
/*   Updated: 2018/02/13 21:14:21 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void put_link(t_rooms **tmp1, t_rooms *tmp2)
{
	t_links *buf;

	buf = ft_memalloc(sizeof(t_links));
	buf->adr = tmp2;
	buf->next = NULL;
	buf->next = (*tmp1)->trans;
	(*tmp1)->trans = buf;
}

void get_links(t_rooms **hash,char *temp)
{
	t_rooms *tmp1;
	t_rooms	*tmp2;
	char	**str;

	while (1)
	{
		str = ft_strsplit(temp, '-');
		tmp1 = hash_find_cell(hash, str[0]);
		tmp2 = hash_find_cell(hash, str[1]);
		if (!tmp1 || !tmp2 || str[2] || str[0][0] == 'L')
			error();
		put_link(&tmp1, tmp2);
		put_link(&tmp2, tmp1);
		get_print(0, &temp);
		free_double_pointer (&str);
		if (temp[0] == '#')
			get_print(0, &temp);
		if (!ft_strlen(temp))
			break;
	}
}

void find_distance(t_rooms *room, int dist)
{
	t_rooms *tmp;
	t_links *tmp2;

	tmp = room;
	tmp2 = room->trans;
	room->dist = CHECK_MIN(dist, room->dist);
	while (tmp2)
	{
		tmp2->adr->dist = CHECK_MIN(room->dist + 1, tmp2->adr->dist);
		tmp2 = tmp2->next;
	}
	tmp2 = room->trans;
	room->ant_n = -1;
	while (tmp2)
	{
		
		if (tmp2->adr->ant_n != -1)
			find_distance(tmp2->adr, room->dist + 1);
		tmp2 = tmp2->next;
	}
}

int check_max_count(t_rooms **hash)
{
	int i;
	int k;
	t_links *tmp;

	i = 0;
	k = 0;
	tmp = hash[get_key(g_start)]->trans;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = hash[get_key(g_end)]->trans;
	while (tmp)
	{
		k++;
		tmp = tmp->next;
	}
	if (!i || !k)
		error();
	return(CHECK_MIN(i,k));
}

t_rooms *check_lowest_val(t_links *current,int mod)
{
	t_links *temp_link;
	t_rooms *temp_room;

	if (!current)
		return (NULL);
	temp_link = current;
	while (current && current->adr)
	{
		//ft_printf("		name = [%s] dist = [%d], cur dist = [%d] ant_n = [%d]\n", current->adr->name, current->adr->dist, temp_link->adr->dist, current->adr->ant_n);
		if ((current->adr->ant_n != 0 || ft_strequ(current->adr->name, g_start))
			&& current->adr->dist < temp_link->adr->dist + mod)
		{
			if (current->adr->ant_n == -3)
				current->adr->ant_n = 0;
			else
				current->adr->ant_n = -3;
			break;
		}
		current = current->next;
	}
	temp_room = current->adr;	
	current = temp_link;
	return(temp_room);
}
