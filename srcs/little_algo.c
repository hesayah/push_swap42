/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 03:52:50 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/17 20:36:31 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	run_little(t_data *data)
{
	t_lst	*ptr_a;
	t_lst	*ptr_b;

	ptr_a = data->a_pile;
	ptr_b = data->b_pile;
	if (check_order(&data->a_pile))
		return ;
	if (ptr_a->value == data->max_value)
		ra(data);
	else if (ptr_a->value < ptr_a->next->value)
		rra(data);
	else if (ptr_a->value > ptr_a->next->value)
		sa(data);
}

static void	put_min_and_max_to_b(t_data *data)
{
	int	pos_max_value;
	int	pos_min_value;

	pos_max_value = nb_of_strokes(data, &data->a_pile, data->max_value);
	if (pos_max_value > (int)(data->len_a / 2))
		while (data->a_pile->value != data->max_value)
			rra(data);
	else
		while (data->a_pile->value != data->max_value)
			ra(data);
	pb(data);
	pos_min_value = nb_of_strokes(data, &data->a_pile, data->min_value);
	if (pos_min_value > (int)(data->len_a / 2))
		while (data->a_pile->value != data->min_value)
			rra(data);
	else
		while (data->a_pile->value != data->min_value)
			ra(data);
	pb(data);
}

int	little_algo(t_data *data)
{
	int	i;

	i = 0;
	if (data->len_a <= 3)
		while (!check_order(&data->a_pile))
			run_little(data);
	else
	{
		put_min_and_max_to_b(data);
		while (!check_order(&data->a_pile))
			run_little(data);
		pa(data);
		pa(data);
		ra(data);
	}
	return (clean_up(data));
}
