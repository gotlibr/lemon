/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:13:51 by hlriabts          #+#    #+#             */
/*   Updated: 2017/11/11 13:59:13 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i - 1] != c)
			count++;
	}
	return (count);
}

static void		move(char const **s, int *n)
{
	while (*n > 0)
	{
		(*n)--;
		(*s)++;
	}
}

static void		clear_mem(char ***str, int i)
{
	while (i >= 0)
	{
		free((*str)[i]);
		i--;
	}
	free(*str);
}

static void		*fill(char const *s, char c, char ***str)
{
	int i;
	int n;
	int k;

	k = -1;
	i = -1;
	n = 0;
	while (word_count(s, c) > 0)
	{
		while (*s == c)
			s++;
		while (s[n] != c && s[n] != '\0')
			n++;
		if (!((*str)[++i] = ft_memalloc(n + 1)))
		{
			clear_mem(str, i);
			return (NULL);
		}
		while (++k < n)
			(*str)[i][k] = s[k];
		k = -1;
		move(&s, &n);
	}
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char **str;

	if (!s)
		return (NULL);
	if (!(str = ft_memalloc((word_count(s, c) + 1) * sizeof(char *))))
		return (NULL);
	if (!fill(s, c, &str))
		return (NULL);
	return (str);
}
