/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:39:24 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/07 09:02:42 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*static void	rotate_down(t_lst **lst_pile)
{
	int		last_value;
	t_lst		*tmp;

	if (!lst_pile)
		return ;
	tmp = (*lst_pile)->next;
	if (tmp->next)
		while (tmp->next)
			lst_pile = tmp->next;
	last_value = tmp->value;
	if (tmp->previous)
		while (tmp->previous)
		{
			tmp->value = tmp->previous->value;
			lst_pile = tmp->previous;
		}
	(*lst_pile)->value = last_value;
}

void	rra(t_data **data)
{
	if (!data->a_pile)
		return ;
	rotate_down(data->a_pile);
}

void	rrb(t_data **data)
{
	if (!data->b_pile)
		return ;
	rotate_down(data->b_pile);
}

void	rrr(t_data **data)
{
	if (!data->a_pile || !data->b_pile)
		return ;
	rotate_down(data->a_pile);
	rotate_down(data->b_pile);
}*/