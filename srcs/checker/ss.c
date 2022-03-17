/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 12:24:28 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/17 20:36:31 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

static void	swap(t_lst **lst_pile)
{
	int	tmp_value;

	tmp_value = (*lst_pile)->value;
	(*lst_pile)->value = (*lst_pile)->next->value;
	(*lst_pile)->next->value = tmp_value;
}

void	sa_checker(t_data *data)
{
	if (data->a_pile && data->a_pile->next)
		swap(&data->a_pile);
}

void	sb_checker(t_data *data)
{
	if (data->b_pile && data->b_pile->next)
		swap(&data->b_pile);
}

void	ss_checker(t_data *data)
{
	if (data->a_pile && data->a_pile->next
		&& data->b_pile && data->b_pile->next)
	{
		sa(data);
		sb(data);
	}
}
