/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:58:21 by hlriabts          #+#    #+#             */
/*   Updated: 2018/02/13 21:03:54 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LEM_IN_H
# define LEM_IN_H

#include "libftprintf/ft_printf.h"

typedef struct s_rooms
{
	char		*name;
	int			x;
	int			y;
	int			ant_n;
	int			dist;
	struct s_rooms		*next;
	struct s_links		*trans;
}				t_rooms;

typedef struct s_links
{
	t_rooms *adr;
	struct s_links *next;
}				t_links;

char	*g_start;
char	*g_end;
int		g_ant_count;
int     g_count;
t_rooms *parsing(t_rooms *prev_list, char **tmp);
void free_double_pointer(char ***str);
t_rooms *init_prev(t_rooms *list, char *nam, char *x, char *y);
void error(void);
void create_hash(t_rooms *list, char *temp);
int get_key(char *name);
t_rooms *copy_list(t_rooms *list);
t_rooms *copy_list_2(t_rooms *list);
t_rooms **create_table (t_rooms *list);
int get_key(char *name);
t_rooms *hash_find_cell(t_rooms **hash, char *str);
void put_link(t_rooms **tmp1, t_rooms *tmp2);
void get_links(t_rooms **hash,char *temp);
void find_distance(t_rooms *room, int dist);
int check_max_count(t_rooms **hash);
t_rooms *check_lowest_val(t_links *current,int mod);
void push_ants(t_rooms **ways);
void print_turn (t_rooms **ways);
int add_new_ant(t_rooms **ways, int n);
int check_if_all (t_rooms **ways);
void lets_go(t_rooms **ways);
t_rooms *find_single_way(t_rooms *end);
int list_length(t_rooms *list);
void find_ways(t_rooms **hash);
void create_hash(t_rooms *list,char *temp);
int get_print(int fd, char **tmp);
void free_rooms(t_rooms **list);

#endif

/*Хэш таблица комнат, ключ-хеширования - имя, в хэш-таблице хранится
список переходов из данной комнаты, в виде списка ссылок на структуру*/