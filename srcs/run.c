/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:44:13 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/12 09:24:28 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_order_d(t_lst	**lst_pile)
{
	t_lst	*tmp_one;
	int		value;

	tmp_one = *lst_pile;
	value = tmp_one->value;
	while (tmp_one->next)
	{
		tmp_one = tmp_one->next;
		if (tmp_one->value > value)
			return (0);
		value = tmp_one->value;
	}
	return (1);
}

int	check_order_c(t_lst **lst_pile)
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

int	get_new_top(t_lst **lst)
{
	t_lst *tmp;

	tmp = *lst;
	return (tmp->value);
}

int	run(t_data *data)
{
	if (check_order_c(&data->a_pile))
		return (0);
	pre_working(data);
	while (data->b_pile)
	{
		if ((int)data->a_pile->value < (int)data->b_pile->value)
			pa(data);
		else
			rb(data);
	}
}