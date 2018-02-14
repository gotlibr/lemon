/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:57:35 by hlriabts          #+#    #+#             */
/*   Updated: 2018/01/25 20:29:14 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_join(char **str, char *str2)
{
	char *buf;

	buf = ft_strjoin(*str, str2);
	if (*str)
		free(*str);
	return (buf);
}

int		memory_calc(t_printf *l, int count, int base, int sign)
{
	int	size;

	if ((base == 10 && ft_strchr("dD", l->c) &&
			((sign < 0) || (ft_strchr(l->flags, ' '))
				|| ft_strchr(l->flags, '+'))))
		count++;
	if (base == 8 && ft_strchr(l->flags, '#'))
		count++;
	if (l->min_width >= l->prec && l->min_width > count)
		size = (l->min_width);
	else if (l->min_width < l->prec && l->prec > count)
	{
		size = l->prec;
		if ((base == 10 && ft_strchr("dD", l->c) &&
			((sign < 0) || (ft_strchr(l->flags, ' '))
				|| ft_strchr(l->flags, '+'))))
			size++;
	}
	else
		size = count;
	if (size > l->min_width)
		size += (base == 16 && ft_strchr(l->flags, '#')) ? 2 : 0;
	l->ctent = ft_memalloc((size + 1) * sizeof(char));
	ft_memset(l->ctent, '_', size);
	return (size);
}

void	printf_itoa(t_printf *l, size_t n, int base, int first_s)
{
	char	hex;
	int		i;
	size_t	tmp;
	int		count;

	count = (l->prec == 0 && n == 0) ? 0 : 1;
	i = ft_strlen(l->ctent) - 1;
	tmp = n;
	hex = (l->c == 'X') ? 55 : 87;
	while (tmp /= base)
		count++;
	if (ft_strchr(l->flags, '-') && l->min_width > l->prec)
	{
		i = first_s + count - 1;
		i += (l->ctent[0] == '+' || l->ctent[0] == '-') ? 1 : 0;
		i += (l->prec > count) ? l->prec - count : 0;
	}
	while (count-- != 0)
	{
		l->ctent[i--] = (base == 16 && (n % base) > 9)
		? (n % base) + hex : (n % base) + '0';
		n /= base;
	}
}

int		width_count(t_printf *l, int sign, int count, int base)
{
	int i;

	i = 0;
	if ((base == 10 && ft_strchr("dD", l->c) &&
			((sign < 0) || (ft_strchr(l->flags, ' '))
				|| ft_strchr(l->flags, '+'))))
		i++;
	if (l->prec != 0)
		i += (l->prec > count) ? l->prec - count : 0;
	if (base == 16 && ft_strchr(l->flags, '#'))
		i += 2;
	return (i);
}
