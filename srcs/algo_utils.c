/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:36:40 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/13 19:02:57 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*int	last_little_value(t_data *data, t_lst **lst_pile, int value)
{
	t_lst 	*ptr;
	t_lst	*lst;
	int		pairing;

	ptr = *lst_pile;
	pairing = data->min_value;
	while (ptr)
	{
		lst = ptr->next;
		while (lst)
		{
			if (lst->value < value)
			{
				if (lst->value > pairing)
					pairing = lst->value;
			}
			lst = lst->next; 
		}
		ptr = ptr->next;
	}
	if (pairing == data->min_value)
		pairing = value;
	return (pairing);
}*/

int	first_bigger_value(t_data *data, t_lst **lst_pile, int value)
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
	if (pairing == data->max_value)
		pairing = value;
	return (pairing);
}

int	nb_of_strokes(t_data *data, t_lst **lst_pile, int value)
{
	int		nb;
	t_lst	*lst;

	nb = 0;
	lst = *lst_pile;
	if (!lst->next)
		return (0);
	while (lst)
	{
		if (lst->value == value)
			break;
		lst = lst->next;
		nb++;
	}
	return (nb);
}

int	get_the_best_pair(t_data *data)
{
	int		pos_a;
	int		pos_b;
	int		tmp_pos;
	int		best_move[2];
	t_lst	*ptr_b;

	ptr_b = data->b_pile;
	pos_b = 0;
	best_move[0] = data->len_b;
	best_move[1] = ptr_b->value;
	while (ptr_b)
	{
		pos_a = nb_of_strokes(data, &data->a_pile,
		first_bigger_value(data, &data->a_pile, ptr_b->value));
		if (pos_a > data->len_a / 2)
			pos_a = data->len_a - pos_a;
		if (pos_b > data->len_b / 2)
			tmp_pos = pos_a + (data->len_b - pos_b);
		else
			tmp_pos = pos_a + pos_b;
		if (best_move[0] > tmp_pos)
		{
			best_move[0] = tmp_pos;
			best_move[1] = ptr_b->value;
		}
		pos_b++;
		ptr_b = ptr_b->next;
	}
	return (best_move[1]);
}

int		do_the_move(t_data *data)
{
	int pos_a;
	int	pos_b;
	int	best;

	best = get_the_best_pair(data);
	pos_a = nb_of_strokes(data, &data->a_pile, first_bigger_value(data, &data->a_pile, best));
	pos_b = nb_of_strokes(data, &data->b_pile, best);
	while ((data->len_a > pos_a && pos_a > (data->len_a / 2)) || ((data->len_b > pos_b && pos_b > data->len_b / 2)))
	{
		if ((data->len_a > pos_a && pos_a > (data->len_a / 2)) && ((data->len_b > pos_b && pos_b > data->len_b / 2)))
		{
			pos_a++;
			pos_b++;
			rrr(data);
		}
		else if (data->len_a > pos_a && pos_a > (data->len_a / 2))
		{
			rra(data);
			pos_a++;
		}
		else if (data->len_b > pos_b && pos_b > (data->len_b / 2))
		{
			rrb(data);
			pos_b++;
		}
	}
	while ((pos_a &&  pos_a <= (data->len_a / 2)) || (pos_b &&  pos_b <= (data->len_b / 2)))
	{
		if ((pos_a && pos_a <= (data->len_a / 2)) && (pos_b && pos_b <= (data->len_b / 2)))
		{	
			rr(data);
			pos_a--;
			pos_b--;
			//printf("pos_a[%i]\n", pos_a);
			//printf("pos_b[%i]\n", pos_b);
				//break;
		
		}
		else if (pos_a && pos_a <= (data->len_a / 2))
		{
			ra(data);
			//printf("pos_b[%i]\n", pos_b);
				//break;
			pos_a--;
		}
		else if (pos_b && pos_b <= (data->len_b / 2))
		{
			rb(data);
			//printf("pos_b[%i]\n", pos_b);
			//	break;
			pos_b--;
		}
	}
	return (0);
}