/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:44:13 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/16 23:58:43 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_order(t_lst **lst_pile)
{
	t_lst	*tmp_one;
	int		value;

	tmp_one = *lst_pile;
	value = tmp_one->value;
	while (tmp_one->next)
	{
		tmp_one = tmp_one->next;
		if (tmp_one->value < value)
			return (0);
		value = tmp_one->value;
	}
	return (1);
}

int	run(t_data *data)
{
	int	nb_strokes;

	if (check_order(&data->a_pile))
		return (0);
	pre_working(data);
	while (data->b_pile)
	{
		calibrate_pile(data);
		pa(data);
	}
	nb_strokes = nb_of_strokes(data, &data->a_pile, data->min_value);
	if (nb_strokes < (int)(data->len_a / 2))
		while (!check_order(&data->a_pile))
			ra(data);
	else
		while (!check_order(&data->a_pile))
			rra(data);
	return (clean_up(data));
}
