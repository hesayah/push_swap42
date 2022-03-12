/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 12:24:28 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/12 03:50:18 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_lst **lst_pile)
{
	t_lst		*ptr_first;
	int			value;
	int			value_next;

	ptr_first = (*lst_pile);
	value = ptr_first->value;
	*lst_pile = ptr_first->next;
	value_next = (*lst_pile)->value;
	(*lst_pile)->value = value;
	ptr_first->value = value_next;
}

void	sa(t_data *data)
{
	if (data->a_pile && data->a_pile->next)
	{
		swap(&data->a_pile);
		ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_data *data)
{
	if (data->b_pile && data->b_pile->next)
	{
		swap(&data->b_pile);
		ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_data *data)
{
	if (data->a_pile && data->a_pile->next
		&& data->b_pile && data->b_pile->next)
	{
		sa(data);
		sb(data);
		ft_putstr_fd("ss\n", 1);
	}
}
