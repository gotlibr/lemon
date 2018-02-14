/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:24:19 by hlriabts          #+#    #+#             */
/*   Updated: 2017/11/02 14:28:40 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char	*arr;
	size_t			count;
	int				i;

	arr = (unsigned char *)destination;
	i = 0;
	count = 0;
	while (count < n)
	{
		arr[i] = c;
		count += sizeof(destination[i]);
		i++;
	}
	return (arr);
}
