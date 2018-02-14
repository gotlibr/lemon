/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:19:44 by hlriabts          #+#    #+#             */
/*   Updated: 2017/11/08 14:35:42 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s != NULL && (f) != NULL)
	{
		if ((str = (char*)malloc(ft_strlen(s) + 1)) == NULL)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			str[i] = (f)(i, (char)s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
