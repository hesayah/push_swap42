/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:36:40 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/16 05:24:00 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_pair(t_data *data, t_lst **lst_pile, int value)
{
	t_lst 	*ptr;
	int		pairing;

	pairing = data->max_value;
	ptr = *lst_pile;
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

static int	get_the_best_pair(t_data *data)
{
	int		pos_a;
	int		pos_b;
	int		tmp_pos;
	int		best_move[2];
	t_lst	*ptr_b;

	pos_b = 0;
	ptr_b = data->b_pile;
	best_move[0] = data->len_b -1;
	best_move[1] = ptr_b->value;
	while (ptr_b)
	{
		pos_a = nb_of_strokes(data, &data->a_pile, get_pair(data, &data->a_pile, ptr_b->value));
		if (pos_a > (int)(data->len_a / 2))
			pos_a = data->len_a - pos_a;
		if (pos_b > (int)(data->len_b / 2))
			tmp_pos = pos_a + data->len_b - pos_b;
		else
			tmp_pos = pos_a + pos_b;
		if (best_move[0] > (int)tmp_pos)
		{
			best_move[0] = (int)tmp_pos;
			best_move[1] = ptr_b->value;
		}
		pos_b++;
		ptr_b = ptr_b->next;
	}
	return (best_move[1]);
}

/*int		test(t_data *data,int pos_a, int pos_b,  int option)
{
	if (option == 1)
	{
		while ((data->len_a > pos_a && pos_a > (int)(data->len_a / 2)) && (data->len_b > pos_b && pos_b > (int)(data->len_b / 2)))
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
	else
	{
		while (pos_a && pos_a < (int)(data->len_a / 2) && pos_b && pos_b <= (int)(data->len_b / 2))
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
}*/



int		calibrate_pile(t_data *data)
{
	int pos_a;
	int	pos_b;
	int	best_value;

	best_value = get_the_best_pair(data);
	pos_a = nb_of_strokes(data, &data->a_pile, get_pair(data, &data->a_pile, best_value));
	pos_b = nb_of_strokes(data, &data->b_pile, best_value);
	//test(data, pos_a, pos_b, 1);
	//test(data, pos_a, pos_b, 0);
	while ((data->len_a > pos_a && pos_a > (int)(data->len_a / 2)) && (data->len_b > pos_b && pos_b > (int)(data->len_b / 2)))
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
	while (pos_a && pos_a < (int)(data->len_a / 2) && pos_b && pos_b <= (int)(data->len_b / 2))
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
	pa(data);
	//print_pile(data);
	return (0);
}