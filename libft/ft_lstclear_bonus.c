/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:17:02 by hesayah           #+#    #+#             */
/*   Updated: 2021/12/11 05:31:37 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_lst **lst, void (*del)(int))
{
	t_lst	*elem;
	t_lst	*tmp;

	if (!lst || !del)
		return ;
	elem = *lst;
	while (elem)
	{
		tmp = elem->next;
		ft_lstdelone(elem, del);
		elem = tmp;
	}
	*lst = NULL;
}
