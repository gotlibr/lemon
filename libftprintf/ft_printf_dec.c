/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 00:59:54 by hlriabts          #+#    #+#             */
/*   Updated: 2018/01/25 16:59:26 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pre_width(t_printf *l, int size, int count)
{
	int i;

	i = (ft_strchr(l->flags, '-')) ? size - 1 : 0;
	while (l->min_width > count)
	{
		if (ft_strchr(l->flags, '0') && l->prec == -1
			&& !ft_strchr(l->flags, '-'))
			l->ctent[i] = '0';
		else
			l->ctent[i] = ' ';
		count++;
		i += (ft_strchr(l->flags, '-')) ? -1 : 1;
	}
	return (i);
}

int		sign_hash(t_printf *l, int base, int sign, int count)
{
	int i;

	i = 0;
	count += (base == 16 && ft_strchr(l->flags, '#')) ? 2 : 1;
	if (!ft_strchr(l->flags, '-'))
		while (l->ctent[i] == ' ' && i < (int)ft_strlen(l->ctent) - count)
			i++;
	if (base % 8 == 0 && ft_strchr(l->flags, '#'))
		l->ctent[i++] = '0';
	if (base == 16 && ft_strchr(l->flags, '#'))
		l->ctent[i++] = l->c;
	else if (base == 10 && sign > 0 && ft_strchr("dD", l->c))
	{
		if (ft_strchr(l->flags, ' '))
			l->ctent[i] = ' ';
		if (ft_strchr(l->flags, '+'))
			l->ctent[i] = '+';
	}
	else if (base == 10 && sign < 0 && ft_strchr("dD", l->c))
		l->ctent[i] = '-';
	return (i);
}

void	precision_check(t_printf *l)
{
	int i;

	i = 0;
	while (l->ctent[i] != '\0')
	{
		if (l->ctent[i] == '_')
			l->ctent[i] = '0';
		i++;
	}
}

void	int_printf(t_printf *l, size_t n, int sign)
{
	size_t	tmp;
	int		size;
	int		base;
	int		count;

	count = (l->prec == 0 && n == 0) ? 0 : 1;
	base = (ft_strchr("oO", l->c)) ? 8 : 10;
	base = (ft_strchr("xX", l->c)) ? 16 : base;
	tmp = n;
	while (tmp /= base)
		count++;
	if (n == 0 && ft_strchr("oOxX", l->c) && !ft_strchr(l->flags, 'p'))
	{
		size = (ft_strchr(l->flags, '#') && ft_strchr("oO", l->c)
			&& l->prec != -1) ? count + 1 : count;
		l->ctent = ft_memalloc((size + 1) * sizeof(char));
		ft_memset(l->ctent, '_', size);
	}
	else
		size = memory_calc(l, count, base, sign);
	tmp = pre_width(l, size, width_count(l, sign, count, base) + count);
	if (!(n == 0 && ft_strchr("oOxX", l->c) && !ft_strchr(l->flags, 'p')))
		tmp = sign_hash(l, base, sign, count);
	printf_itoa(l, n, base, tmp);
	precision_check(l);
}

void	pre_int(t_printf *l, va_list ap)
{
	size_t		buf;
	long long	buf2;
	int			sign;

	if (ft_strchr("DOU", l->c))
		l->cf = (l->cf == '0') ? 'l' : 'L';
	l->c = (ft_strchr("DOU", l->c)) ? ft_tolower(l->c) : l->c;
	(l->c == 'd' && l->cf == 'H') ? buf2 = (char)va_arg(ap, int) : 1;
	(l->c != 'd' && l->cf == 'H') ? buf = (unsigned char)va_arg(ap, int) : 1;
	(l->c != 'd' && l->cf == 'h') ? buf = (unsigned short)va_arg(ap, int) : 1;
	(l->c == 'd' && l->cf == 'h') ? buf2 = (short)va_arg(ap, int) : 1;
	(l->c != 'd' && l->cf == 'l') ? buf = va_arg(ap, unsigned long) : 1;
	(l->c == 'd' && l->cf == 'l') ? buf2 = va_arg(ap, long) : 1;
	(l->c != 'd' && l->cf == 'L') ? buf = va_arg(ap, unsigned long long) : 1;
	(l->c == 'd' && l->cf == 'L') ? buf2 = va_arg(ap, long long) : 1;
	(l->c != 'd' && l->cf == 'z') ? buf = va_arg(ap, size_t) : 1;
	(l->c == 'd' && l->cf == 'z') ? buf2 = va_arg(ap, size_t) : 1;
	(l->c == 'd' && l->cf == 'j') ? buf2 = va_arg(ap, intmax_t) : 1;
	(l->c != 'd' && l->cf == 'j') ? buf = va_arg(ap, uintmax_t) : 1;
	(l->cf == '0' && (l->c == 'd')) ? buf2 = (va_arg(ap, int)) : 1;
	(l->cf == '0' && (ft_strchr("ouxX", l->c)))
		? buf = (unsigned int)(va_arg(ap, int)) : 1;
	sign = ((l->c == 'd' || l->c == 'D') && buf2 < 0) ? -1 : 1;
	buf = ((l->c == 'd' || l->c == 'D')) ? (buf2 * sign) : buf;
	int_printf(l, buf, sign);
}
