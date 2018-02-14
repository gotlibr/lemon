/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 21:02:48 by hlriabts          #+#    #+#             */
/*   Updated: 2018/02/13 21:13:17 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void push_ants(t_rooms **ways)
{
	int i;
	int tmp1;
	int tmp2;
	t_rooms *tmp;

	i = 0;
	tmp1 = 0;
	tmp2 = 0;
	
	while (ways[i])
	{
		tmp = ways[i];
		while (ways[i])
		{
			if (ways[i]->ant_n > 0)
				tmp2 = ways[i]->ant_n;
			ways[i]->ant_n = tmp1;
			tmp1 = tmp2;
			tmp2 = 0;
			ways[i] = ways[i]->next;
		}
		ways[i] = tmp;
		i++;
	}
}
void dop_print(t_rooms *way, int cur)
{
	if (way)
			way = way->next;
		while (way)
		{
			if (way->ant_n == cur)
			{
				ft_printf("L%d-%s ",way->ant_n, way->name);
			if (ft_strequ(way->name, g_end))
				way->ant_n = 0;
			}
			way = way->next;
		}
}
void print_turn (t_rooms **ways)
{
	int i;
	t_rooms *tmp;
	int cur;

	cur = 1;
	i = 0;
	while (cur <= g_ant_count)
	{
	while (ways[i])
	{
		tmp = ways[i];
		dop_print(ways[i], cur);
		ways[i] = tmp;
		i++;
	}
	cur++;
	i = 0;
	}
}

int add_new_ant(t_rooms **ways, int n)
{
	int i;
	int k;

	i = 0;
	k = CHECK_MAX(n,1);
	// k = n;
	while (ways[i] && k <= g_ant_count)
	{
		ways[i]->ant_n = k;
		i++;
		k++;
	}
	return(k);
}

int check_if_all (t_rooms **ways)
{
	int k;
	t_rooms *tmp;
	int i;

	i = 0;
	k = 0;
	while (ways[i])
	{
		tmp = ways[i];
		while(ways[i])
		{
			if (ways[i]->ant_n > 0)
				k++;
			ways[i] = ways[i]->next;
		}
		ways[i] = tmp;
		i++;
	}
	return(k);
}

void lets_go(t_rooms **ways)
{
	int i;

	i = 0;
	while (i <= g_ant_count || check_if_all(ways) != 0)
	{			
		push_ants(ways);
		if (i <= g_ant_count)
			i = add_new_ant(ways, i);
		print_turn(ways);
		ft_printf("\n");
	}
}