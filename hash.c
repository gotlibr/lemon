/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:12:51 by hlriabts          #+#    #+#             */
/*   Updated: 2018/02/13 21:08:04 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void error(void)
{
	ft_printf("Error\n");
	exit(0);
}

t_rooms *find_single_way(t_rooms *end)
{
	t_rooms *way;
	t_rooms *way_tmp;

	way = copy_list_2(end);
	while (end && end->name)
	{
		way_tmp = way;
		if (ft_strequ(way->name, g_start))
			break;
		//ft_printf("current name = %s\n", end->name);
		if (check_lowest_val(end->trans, 0))
			end = check_lowest_val(end->trans, 0);
		else 
		{
			if (check_lowest_val(end->trans, 1))
				end = check_lowest_val(end->trans, 1);
			else 
			 	end = check_lowest_val(end->trans, 2);
			if (!end)
				return (way);
		}
		way = copy_list_2(end);
		way->next = way_tmp;
	}
	return(way);
}

int list_length(t_rooms *list)
{
	int i;
	t_rooms *temp;

	temp = list;
	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	list = temp;
	return (i);
}
void find_dubs(t_rooms **ways)
{
	int i;
	int k;

	k = 0;
	i = 1;
	while(ways[k])
		k++;
	if (k == 0)
		error();
	if (!ways[i])
		return ;
	while (ways[i])
	{
		if (ft_strequ(g_end, ways[i]->next->name))
		{
			free(ways[i]);
			ways[i] = NULL;
		}
	i++;
	}
	return ;
}

void find_ways(t_rooms **hash)
{
	int count;
	int k;
	int i;
	t_rooms **ways;

	i = 0;
	k = 0;
	count = check_max_count(hash);
	ways = (t_rooms **)ft_memalloc(sizeof(t_rooms*) * (count + 1));
	while (count > 0 && i  <= g_ant_count)
	{
		ways[k] = find_single_way(hash_find_cell(hash,g_end));
		if (!(ways[k]))
			break;
		i += list_length(ways[k]);
		count--;
		k++;
	}
	find_dubs(ways);
	lets_go(ways);
	i = 0;
	while(ways[i])
		free_rooms(&ways[i++]);
	free(ways);
	/*TEST*/
	// while (ways[0])
	// {
	// 	ft_printf("%s->",ways[0]->name);
	// 	ways[0] = ways[0]->next;
	// }
	// ft_printf("\n");
	// while (ways[1])
	// {
	// 	ft_printf("%s->",ways[1]->name);
	// 	ways[1] = ways[1]->next;
	// }
	// ft_printf("\n");
	// while (ways[2])
	// {
	// 	ft_printf("%s->",ways[2]->name);
	// 	ways[2] = ways[2]->next;
	// }
	// ft_printf("\n");
	// // while (ways[3])
	// // {
	// // 	ft_printf("%s->",ways[3]->name);
	// // 	ways[3] = ways[3]->next;
	// // }
}
void create_hash(t_rooms *list, char *temp)
{
	t_rooms *head;
	t_rooms **hash;

	head = list;
	g_count = 0;
	while (list)
	{
		g_count++;
		list = list->next;
	}
	list = head;
	hash = create_table(list);
	free_rooms(&list);
	get_links(hash, temp);
	find_distance(hash_find_cell(hash,g_start),0);
	find_ways(hash);
	free(hash);
	/*TEST*/
	// int i = 0;
	// while (i < g_count)
	// 	{
	// 		if (hash[i])
	// 		{
	// 			while (hash[i])
	// 			{
	// 				ft_printf("name :[%s] ind %d distance[%d]\n", hash[i]->name,i, hash[i]->dist);
	// 				while (hash[i]->trans && hash[i]->trans->adr)
	// 				{
	// 						ft_printf("link :[%s]\n",hash[i]->trans->adr->name);
	// 					hash[i]->trans = hash[i]->trans->next;
	// 				}
	// 				hash[i] = hash[i]->next;				
	// 			}
	// 		}
	// 		i++;
	// 	}
}