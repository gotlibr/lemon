/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:26:24 by hlriabts          #+#    #+#             */
/*   Updated: 2018/02/06 20:40:40 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "lem_in.h"

t_rooms *init_prev(t_rooms *list, char *nam, char *x, char *y)
{
	t_rooms *head;

	head = list;
	while (list)
	{
		if (ft_strequ(list->name, nam) || ((list->x ==  ft_atoi(x)) && (list->y ==  ft_atoi(y))))
			error();
		list = list->next;
	}
	list = (t_rooms *)malloc(sizeof(t_rooms));	
	list->name = ft_strdup(nam);
	list->x = ft_atoi(x);
	list->y = ft_atoi(y);
	list->ant_n = 0;
	list->dist = INT_MAX;
	list->next = head;
	list->trans = NULL;
	return(list);
}
void free_double_pointer(char ***str)
{
	char **head;
	int i;

	i = 0;

	head = *str;
	while (*str && *str[i])
	{
		ft_strdel(*str);
		(*str)++;
	}
	if (head)
		free(head);
	head = NULL;
}

int check_start_end(char **tmp, char ***str)
{
	if (ft_strequ(*tmp, "##start"))
	{
		if (g_start)
			error();
		get_print(0, tmp);
		*str = ft_strsplit(*tmp, ' ');
		g_start = ft_strdup((*str)[0]);
		free_double_pointer(str);
		return (1);
	}
	else if (ft_strequ(*tmp, "##end"))
	{
		if (g_end)
			error();
		get_print(0, tmp);
		*str = ft_strsplit(*tmp, ' ');
		g_end = ft_strdup((*str)[0]);
		free_double_pointer(str);
		return (1);
	}
	return (0);
}

t_rooms *parsing(t_rooms *prev_list, char **tmp)
{
	char	**str;

	get_print(0, tmp);
	g_ant_count = ft_atoi(*tmp);
	str = NULL;
	while (get_print(0,tmp))
	{
		free_double_pointer(&str);
		if (ft_strchr(*tmp,'#') && !check_start_end(tmp, &str))
			while (ft_strchr(*tmp,'#'))
				get_print(0,tmp);
		str = ft_strsplit(*tmp,' ');
		if (str[0] && str[1] && str[2] && !str[3])
			prev_list = init_prev(prev_list, str[0], str[1], str[2]);
		else 
			break;
	}
	// ft_printf("ant count = %d, start = %s, end = %s\n", g_ant_count, g_start, g_end);
	if (!g_start || !g_end || g_ant_count <= 0 )
		error();
	free_double_pointer(&str);
	return (prev_list);
}
int get_print(int fd, char **tmp)
{
	int i;
	if (*tmp)
		free(*tmp);
	i = get_next_line(fd, tmp);
	if (ft_strlen(*tmp))
		ft_printf("%s\n", *tmp);
	return (i);
}
int main(void)
{
	t_rooms *prev_list;
	char	*temp;

	prev_list = NULL;
	g_start = NULL;
	g_end = NULL;
	temp = NULL;
	prev_list = parsing(prev_list, &temp);
	// if (ft_strlen(temp) < 3)
	// 	error();
	/*TEST*/
	create_hash(prev_list, temp);
	system("leaks lem-in");
	return 0;
}