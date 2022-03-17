/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:36:40 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/17 03:12:59 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_pair(t_data *data, t_lst **lst_pile, int value)
{
	int		pairing;
	t_lst	*ptr;

	ptr = *lst_pile;
	pairing = data->max_value;
	while (ptr)
	{
		if (ptr->value > value)
		{
			if (ptr->value < pairing)
				pairing = ptr->value;
		}
		ptr = ptr->next;
	}
	return (pairing);
}

int	nb_of_strokes(t_data *data, t_lst **lst_pile, int value)
{
	int		nb;
	t_lst	*lst;

	nb = 0;
	lst = *lst_pile;
	while (lst)
	{
		if (lst->value == value)
			return (nb);
		nb++;
		lst = lst->next;
	}
	return (nb);
}

static void	calculate_best_value(t_data *data, t_lst *ptr_b,
		int pos_b, int *best_value)
{
	int	pos_a;
	int	pos_value;
	int	best_pos_value;

	best_pos_value = data->len_b;
	while (ptr_b)
	{
		pos_a = nb_of_strokes(data, &data->a_pile,
				get_pair(data, &data->a_pile, ptr_b->value));
		if (pos_a > (int)(data->len_a / 2))
			pos_a = data->len_a - pos_a;
		if (pos_b > (int)(data->len_b / 2))
			pos_value = pos_a + data->len_b - pos_b;
		else
			pos_value = pos_a + pos_b;
		if (best_pos_value > (int)pos_value)
		{
			best_pos_value = (int)pos_value;
			(*best_value) = ptr_b->value;
		}
		pos_b++;
		ptr_b = ptr_b->next;
	}
}

int	get_the_best_pair(t_data *data)
{
	int		pos_b;
	int		best_value;
	t_lst	*ptr_b;

	pos_b = 0;
	ptr_b = data->b_pile;
	best_value = ptr_b->value;
	calculate_best_value(data, ptr_b, pos_b, &best_value);
	return (best_value);
}
