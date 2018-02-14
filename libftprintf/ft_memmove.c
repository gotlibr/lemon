/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:45:05 by hlriabts          #+#    #+#             */
/*   Updated: 2017/11/11 17:08:47 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dstit;
	unsigned char	*srcit;
	size_t			i;

	dstit = (unsigned char*)dest;
	srcit = (unsigned char*)src;
	i = 0;
	if (srcit < dstit)
	{
		while (i < len)
		{
			dstit[len - i - 1] = srcit[len - i - 1];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			dstit[i] = srcit[i];
			i++;
		}
	}
	return (dest);
}
