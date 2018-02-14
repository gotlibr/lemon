/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:06:14 by hlriabts          #+#    #+#             */
/*   Updated: 2018/01/25 20:27:54 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*list_init(t_printf *list)
{
	list = (t_printf *)malloc(sizeof(t_printf));
	(list)->next = NULL;
	list->flags = NULL;
	list->cf = '0';
	list->min_width = 0;
	list->prec = -1;
	list->pre_con = NULL;
	list->ctent = NULL;
	list->dop_ind = 0;
	return (list);
}

int			pre_con_cpy(const char *form, t_printf **list, int *start)
{
	int i;

	i = *start;
	while (form[i] != '%' && form[i] != '\0')
		i++;
	if (ft_strlen(form) == 1 && form[i] == '%')
		return (0);
	if (i > *start)
		(*list)->pre_con = ft_strsub(form, *start, i - *start);
	*start = i + 1;
	return (1);
}

int			find_conv_prec_width(const char *form, int start, t_printf *list)
{
	int		i;
	char	*not_cons;

	not_cons = "#0-+ hljz.123456789";
	i = -1;
	while (form[start + ++i] != '\0')
		if (ft_strchr(not_cons, form[start + i]) == NULL)
		{
			if (form[start + i] == 'i')
				list->c = 'd';
			else
				list->c = form[start + i];
			break ;
		}
	form = &(form[start + i - 1]);
	while (*form != '%' && (ft_isdigit(*form) || *form == '.'))
		form--;
	form++;
	list->min_width = ABS(ft_atoi(form));
	while (ft_isdigit(*form))
		form++;
	form++;
	if (*(form - 1) == '.')
		list->prec = ABS(ft_atoi(form));
	return (start + i);
}

void		find_flags(const char *f, int st, int end, t_printf *l)
{
	int		i;
	int		count;
	char	*flags;
	char	*c_fls;

	i = -1;
	count = 0;
	flags = "#0-+ ";
	c_fls = "hljz";
	while (++i + st < end)
		count += (ft_strchr(flags, f[st + i]) != NULL) ? 1 : 0;
	i = -1;
	l->flags = (char*)ft_memalloc(sizeof(char) * count + 1);
	while (++i + st < end)
	{
		if (ft_strchr(flags, f[st + i]) != NULL && f[st + i - 1] != '.'
			&& (f[st + i] != '0' || !ft_isdigit(f[st + i - 1])))
			l->flags[ft_strlen(l->flags)] = f[st + i];
		if (ft_strchr(c_fls, f[st + i]) != NULL && l->cf == '0')
		{
			l->cf = f[st + i];
			l->cf = (f[st + i] == 'h' && f[st + i + 1] == 'h') ? 'H' : l->cf;
			l->cf = (f[st + i] == 'l' && f[st + i + 1] == 'l') ? 'L' : l->cf;
		}
	}
}
