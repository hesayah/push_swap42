/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:39:43 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/17 20:36:31 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

static void	rotate_up(t_lst **lst_pile)
{
	t_lst	*tmp_lst;
	int		first_value;

	if (!(*lst_pile)->next)
		return ;
	tmp_lst = (*lst_pile);
	first_value = (*lst_pile)->value;
	while (tmp_lst->next)
	{
		tmp_lst->value = tmp_lst->next->value;
		tmp_lst = tmp_lst->next;
	}
	tmp_lst->value = first_value;
}

void	ra_checker(t_data *data)
{
	if (data->a_pile)
		rotate_up(&data->a_pile);
}

void	rb_checker(t_data *data)
{
	if (data->b_pile)
		rotate_up(&data->b_pile);
}

void	rr_checker(t_data *data)
{
	if (data->a_pile && data->b_pile)
	{
		rotate_up(&data->a_pile);
		rotate_up(&data->b_pile);
	}
}
