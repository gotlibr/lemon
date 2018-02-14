/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 01:00:01 by hlriabts          #+#    #+#             */
/*   Updated: 2017/11/11 17:13:18 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		first_s;
	int		last_s;
	size_t	i;

	i = 0;
	first_s = 0;
	last_s = 0;
	if (s == NULL)
		return (NULL);
	while (i < ft_strlen(s) && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
	{
		first_s++;
		i++;
	}
	i = ft_strlen(s) - 1;
	while (&s[i] > &s[first_s] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
	{
		last_s++;
		i--;
	}
	return (ft_strsub(s, first_s, ft_strlen(s) - last_s - first_s));
}
