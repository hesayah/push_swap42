/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:39:43 by hesayah           #+#    #+#             */
/*   Updated: 2021/12/11 12:25:56 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_up(t_lst **lst_pile)
{
	int	first_value;
	t_lst	*tmp;

	tmp = (*lst_pile);
	first_value = tmp->value;
	if (tmp->next)
		while (tmp->next)
		{
			tmp->value = tmp->next->value;
			lst_pile = tmp->next;
		}
	(*lst_pile)->value = first_value;
}

void	ra(t_data *data)
{
	if (!data->a_pile)
		return ;
	rotate_up(data->a_pile);
}

void	rb(t_data *data)
{
	if (!data->b_pile)
		return ;
	rotate_up(data->b_pile);
}

void	rr(t_data *data)
{
	if (!data->a_pile || !data->b_pile)
		return ;
	rotate_up(data->a_pile);
	rotate_up(data->b_pile);
}
