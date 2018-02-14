/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:19:27 by hlriabts          #+#    #+#             */
/*   Updated: 2017/11/13 12:45:35 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	before(const char **str, int *minus)
{
	while (**str < '0' || **str > '9')
	{
		if (**str != ' ' && (**str < 9 || **str > 13) && **str != 43 &&
			**str != 45)
			return (0);
		if (**str == '-')
		{
			*minus = -1;
			(*str)++;
			break ;
		}
		else if (**str == '+')
		{
			(*str)++;
			break ;
		}
		(*str)++;
	}
	return (1);
}

int			ft_atoi(const char *str)
{
	int num;
	int minus;
	int count;

	minus = 1;
	count = 0;
	num = 0;
	if (before(&str, &minus) == 0)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
		count++;
		if (count == 19)
			return ((minus + 1) / -2);
	}
	return (num * minus);
}
