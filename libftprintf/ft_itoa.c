/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 23:26:42 by hlriabts          #+#    #+#             */
/*   Updated: 2017/11/11 16:46:29 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		iterate(int n)
{
	int i;

	i = 1;
	while (n != 0)
	{
		i *= 10;
		n--;
	}
	return (i);
}

static int		check_size(long buf)
{
	int size;

	size = 0;
	while (buf != 0)
	{
		buf = buf / 10;
		size++;
	}
	return (size);
}

static	char	*copy(char *str, long buf, int size)
{
	int i;

	i = 0;
	if (buf < 0)
	{
		buf *= -1;
		str[i] = '-';
		i++;
	}
	while (size != 0)
	{
		str[i] = (buf / iterate(size - 1)) % 10 + '0';
		i++;
		size--;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	long	buf;
	int		size;
	char	*str;

	buf = n;
	if ((size = check_size(buf)) == 0)
		size++;
	if (buf < 0)
	{
		if ((str = (char *)malloc(size + 2)) == NULL)
			return (NULL);
	}
	else if ((str = (char *)malloc(size + 1)) == NULL)
		return (NULL);
	return (copy(str, buf, size));
}
