/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:44:23 by hlriabts          #+#    #+#             */
/*   Updated: 2017/11/03 00:09:11 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if ((str = malloc(size + 1)) == NULL)
		return (NULL);
	while (size != 0)
	{
		str[size] = 0;
		size--;
	}
	str[size] = 0;
	return (str);
}
