/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:23:30 by hesayah           #+#    #+#             */
/*   Updated: 2021/12/11 11:26:10 by hesayah          ###   ########.fr       */
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
