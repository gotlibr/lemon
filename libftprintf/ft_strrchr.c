/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:59:08 by hlriabts          #+#    #+#             */
/*   Updated: 2017/11/13 12:35:46 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i] == (char)ch)
		return ((char *)&str[i]);
	while (i >= 0)
	{
		if (str[i] == ch)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
