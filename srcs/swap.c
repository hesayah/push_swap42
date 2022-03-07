/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 12:24:28 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/07 09:03:08 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*static void	swap(t_lst **lst_pile)
{
	t_lst		*ptr_first;
	int			value;
	int			value_next;

	ptr_first = (*lst_pile);
	value = ptr_first->value;
	lst_pile = ptr_first->next;
	value_next = (*lst_pile)->value;
	(*lst_pile)->value = value;
	ptr_first->value = value_next;
}

void	sa(t_data *data)
{
	t_lst *tmp_a;

	if (!(data->a_pile))
		return ;
	tmp_a = (data)->a_pile;
	if (!tmp_a->next)
		return ;
	swap(data->a_pile);
}

void	sb(t_data *data)
{
	t_lst *b_ptr;

	if (!*data->b_pile)
		return ;
	b_ptr = data->b_pile;
	if (!b_ptr->next)
		return ;
	swap(data->b_pile);
}

void	ss(t_data *data)
{
	t_lst *a_ptr;
	t_lst *b_ptr;

	if (!(data->a_pile) || !(data->b_pile))
		return ;
	a_ptr = *data->a_pile;
	b_ptr = *data->b_pile;
	if (!a_ptr->next || !b_ptr->next)
		return ;
	sa(data);
	sb(data);
}
*/