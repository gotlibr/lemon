/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:00:16 by hlriabts          #+#    #+#             */
/*   Updated: 2018/01/25 20:24:30 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	*count_uni(int i, int count, unsigned char *res)
{
	int k;
	int push;
	int sum;
	int masks[4];

	push = 0b00111111;
	sum = 0b10000000;
	k = count;
	masks[0] = 0b11111111;
	masks[1] = 0b00011111;
	masks[2] = 0b00001111;
	masks[3] = 0b00000111;
	while (k > 0)
	{
		res[k] = (i & push) + sum;
		i = (i >> 6);
		k--;
	}
	res[k] = (i & masks[count]) + (~masks[count] << 1);
	return (res);
}

void			str_post_flag(t_printf *l)
{
	char	*buf;
	int		i;

	i = 0;
	buf = NULL;
	if (l->ctent[0] == '\0' && (l->c == 'c' || l->c == 'C'))
	{
		l->min_width--;
		l->dop_ind = 1;
	}
	if ((int)ft_strlen(l->ctent) < l->min_width)
	{
		buf = ft_memalloc(l->min_width - ft_strlen(l->ctent) + 1);
		if (ft_strchr(l->flags, '0'))
			ft_memset(buf, '0', l->min_width - ft_strlen(l->ctent));
		else
			ft_memset(buf, ' ', l->min_width - ft_strlen(l->ctent));
		if (ft_strchr(l->flags, '-'))
			l->ctent = ft_join(&(l->ctent), buf);
		else
			l->ctent = ft_join(&(buf), l->ctent);
	}
}

unsigned char	*uni_char(int i)
{
	int				k;
	unsigned char	*res;
	unsigned int	mask;
	int				count;

	mask = 2147483648;
	k = 0;
	while (i && (i & mask) == 0)
	{
		k++;
		mask = mask >> 1;
	}
	count = (32 - k > 7 && 32 - k <= 11) ? 1 : 0;
	count = (32 - k > 11 && 32 - k <= 16) ? 2 : count;
	count = (32 - k > 16) ? 3 : count;
	count = (i == 0) ? 0 : count;
	if (count > MB_CUR_MAX - 1)
		count = MB_CUR_MAX - 1;
	res = (unsigned char *)ft_memalloc((count + 2) * sizeof(char));
	res = count_uni(i, count, res);
	return (res);
}

void			uni_str(t_printf *l, wchar_t *buf, int k)
{
	int				i;
	unsigned char	*temp;
	int				a;
	int				b;

	i = 0;
	b = 0;
	l->prec = (l->prec == -1) ? k * MB_CUR_MAX : l->prec;
	l->ctent = ft_memalloc((k + 1) * MB_CUR_MAX * sizeof(char));
	while (i < k && b < l->prec)
	{
		a = 0;
		if (b < l->prec)
			temp = uni_char(buf[i]);
		if (b + (int)ft_strlen((char *)temp) > l->prec)
			break ;
		while (temp && temp[a] != '\0')
		{
			l->ctent[b] = temp[a];
			b++;
			a++;
		}
		i++;
		free(temp);
	}
}

void			pre_char(t_printf *l, va_list ap, char *buf2, char c)
{
	int		k;
	wchar_t	*buf;

	k = 0;
	if (l->c == 'C' || (l->c == 'c' && l->cf == 'l'))
		l->ctent = (char *)uni_char(va_arg(ap, wint_t));
	else if (l->c == 'S' || (l->c == 's' && l->cf == 'l'))
	{
		buf = str_uni_null(va_arg(ap, wchar_t *));
		while (buf[k] != '\0')
			k++;
		uni_str(l, buf, k);
	}
	else if (l->c == 's')
	{
		l->ctent = ft_memalloc(ft_strlen((char *)buf2) + 1);
		l->prec = (l->prec == -1) ? (int)ft_strlen(buf2) : l->prec;
		l->ctent = ft_strncpy(l->ctent, (char *)buf2,
			CHECK_MIN((int)ft_strlen(buf2), l->prec));
	}
	else
	{
		l->ctent = ft_memalloc(2);
		l->ctent[0] = (c == 'c' || c == 'C') ? va_arg(ap, int) : c;
	}
}
