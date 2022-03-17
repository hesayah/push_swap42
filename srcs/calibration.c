/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calibration.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 00:00:24 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/17 03:23:30 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	do_rotate_down(t_data *data, int pos_a, int pos_b)
{
	while (pos_a && pos_a <= (int)(data->len_a / 2)
		&& pos_b && pos_b <= (int)(data->len_b / 2))
	{	
		rr(data);
		pos_a--;
		pos_b--;
	}
	while (pos_a && pos_a <= (int)(data->len_a / 2))
	{
		ra(data);
		pos_a--;
	}
	while (pos_b && pos_b <= (int)(data->len_b / 2))
	{
		rb(data);
		pos_b--;
	}
}

static void	do_rotate_up(t_data *data, int pos_a, int pos_b)
{
	while ((data->len_a > pos_a && pos_a > (int)(data->len_a / 2))
		&& (data->len_b > pos_b && pos_b > (int)(data->len_b / 2)))
	{
		pos_a++;
		pos_b++;
		rrr(data);
	}
	while (data->len_a > pos_a && pos_a > (int)(data->len_a / 2))
	{
		rra(data);
		pos_a++;
	}
	while (data->len_b > pos_b && pos_b > (int)(data->len_b / 2))
	{
		rrb(data);
		pos_b++;
	}
}

void	calibrate_pile(t_data *data)
{
	int	pos_a;
	int	pos_b;
	int	value_a;
	int	best_value;

	best_value = get_the_best_pair(data);
	value_a = get_pair(data, &data->a_pile, best_value);
	pos_a = nb_of_strokes(data, &data->a_pile, value_a);
	pos_b = nb_of_strokes(data, &data->b_pile, best_value);
	do_rotate_up(data, pos_a, pos_b);
	do_rotate_down(data, pos_a, pos_b);
}
