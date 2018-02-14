/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:16:30 by hlriabts          #+#    #+#             */
/*   Updated: 2017/11/06 23:23:02 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	kb;
	size_t	sb;

	i = 0;
	k = 0;
	sb = ft_strlen(src);
	k = ft_strlen(dest);
	kb = k;
	if (size > kb)
	{
		while (src[i] != '\0' && i < size - kb - 1)
		{
			dest[k] = src[i];
			i++;
			k++;
		}
		dest[k] = '\0';
		return (kb + sb);
	}
	return (sb + size);
}
