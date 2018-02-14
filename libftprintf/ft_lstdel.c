/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:25:14 by hlriabts          #+#    #+#             */
/*   Updated: 2017/11/11 16:34:21 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *buf;

	if (*alst && del)
	{
		while ((*alst)->next != NULL)
		{
			buf = (*alst)->next;
			ft_lstdelone(alst, del);
			(*alst) = buf;
		}
		ft_lstdelone(alst, del);
	}
}
