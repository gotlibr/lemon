/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:00:16 by hlriabts          #+#    #+#             */
/*   Updated: 2017/11/13 12:37:28 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *strb, const char *stra)
{
	int i;

	i = 0;
	if (!*stra)
		return ((char *)strb);
	while (*strb)
	{
		while (strb[i] == stra[i] || stra[i] == '\0')
		{
			if (stra[i] == '\0')
				return ((char *)strb);
			i++;
		}
		i = 0;
		strb++;
	}
	return (NULL);
}
