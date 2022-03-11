/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 23:45:15 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/11 01:42:01 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		check_order(t_lst **lst_pile)
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
	int	i;
	int	j;
	int	max;
	int	new_top;

	i = 0;
	max = data->len_a -1;
	while (!check_order(&data->a_pile))
	{
		j = -1;
	
		while (++j < max)
		{
			new_top = get_new_top(&data->a_pile);
       	 	if ((new_top >> i)&1)
				ra(data); 
       	 	else 
				pb(data);
  	  	}
  	  	while (data->b_pile)
			pa(data);
		i++;
		if (i % 10000 == 0)
			print_pile(&data->a_pile);
	}
	return (0);
}
