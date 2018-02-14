/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 19:43:36 by hlriabts          #+#    #+#             */
/*   Updated: 2018/01/25 20:28:52 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			clear_lst(t_printf *list)
{
	if ((list)->flags)
		free((list)->flags);
	if ((list)->pre_con)
		free((list)->pre_con);
	if ((list)->ctent)
		free((list)->ctent);
	if (list)
		free(list);
}

wchar_t			*str_uni_null(wchar_t *s)
{
	if (!s)
		return (L"(null)");
	else
		return (s);
}

int				print_list(t_printf **list)
{
	int			i;
	t_printf	*buf;

	i = 0;
	while ((*list))
	{
		if ((*list)->pre_con)
			i += write(1, (*list)->pre_con, ft_strlen((*list)->pre_con));
		if ((*list)->ctent)
		{
			write(1, (*list)->ctent, ft_strlen((*list)->ctent));
			i += ft_strlen((*list)->ctent);
			if (((*list)->c == 'c' || (*list)->c == 'C')
				&& (*list)->dop_ind != 0)
				i += write(1, &((*list)->ctent[ft_strlen((*list)->ctent)]), 1);
		}
		buf = (*list)->next;
		clear_lst(*list);
		(*list) = buf;
	}
	return (i);
}

void			function_find(t_printf *list, va_list arguments)
{
	char *buf;

	buf = NULL;
	if (list->c == 'p')
	{
		list->c = 'x';
		list->cf = 'l';
		list->flags = ft_join(&(list->flags), "#p");
	}
	if (ft_strchr("pdiouxXDOU", list->c))
		pre_int(list, arguments);
	else if (ft_strchr("csCS", list->c))
	{
		if (list->c == 's' && list->cf != 'l')
			if (!(buf = va_arg(arguments, char *)))
				buf = "(null)";
		pre_char(list, arguments, buf, list->c);
		str_post_flag(list);
	}
	else
	{
		pre_char(list, arguments, buf, list->c);
		str_post_flag(list);
	}
}

int				ft_printf(const char *form, ...)
{
	t_printf	*arg_list;
	t_printf	*head;
	va_list		ap;
	int			st;
	int			end;

	arg_list = NULL;
	va_start(ap, form);
	st = 0;
	arg_list = list_init(arg_list);
	head = arg_list;
	while (form[st] != '\0')
	{
		if (pre_con_cpy(form, &arg_list, &st) == 0 || form[st - 1] == '\0')
			break ;
		end = find_conv_prec_width(form, st, arg_list);
		find_flags(form, st, end, arg_list);
		function_find(arg_list, ap);
		arg_list->next = list_init(arg_list);
		arg_list = arg_list->next;
		st = end + 1;
	}
	va_end(ap);
	return (print_list(&head));
}
