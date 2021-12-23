/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:42:14 by hesayah           #+#    #+#             */
/*   Updated: 2021/12/11 05:30:49 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_lst *lst, void (*f)(int))
{
	t_lst	*elem;

	if (!lst || !(*f))
		return ;
	elem = lst;
	while (elem)
	{
		f(elem->value);
		elem = elem->next;
	}
}
