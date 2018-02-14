/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:49:04 by hlriabts          #+#    #+#             */
/*   Updated: 2017/11/11 16:47:14 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int ch, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;
	unsigned char	c;

	dst = (unsigned char *)destination;
	src = (unsigned char *)source;
	c = (unsigned char)ch;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		if (src[i] == c)
			return (&dst[i + 1]);
		i += sizeof(source[i]);
	}
	return (NULL);
}
