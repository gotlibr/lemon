/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:45:37 by hlriabts          #+#    #+#             */
/*   Updated: 2017/11/13 12:34:52 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *strb, const char *stra, size_t len)
{
	int i;
	int len_buf;

	i = 0;
	if (!*stra)
		return ((char *)strb);
	while (*strb && len > 0)
	{
		len_buf = len;
		while (strb[i] == stra[i] || stra[i] == '\0')
		{
			if (stra[i] == '\0')
				return ((char *)strb);
			if (len == 0)
				return (NULL);
			i++;
			len--;
		}
		len = len_buf;
		i = 0;
		strb++;
		len--;
	}
	return (NULL);
}
