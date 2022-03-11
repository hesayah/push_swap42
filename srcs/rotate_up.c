/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:39:43 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/11 01:24:41 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_up(t_lst **lst_pile)
{
	t_lst	*tmp;
	int		first_value;

	first_value = (*lst_pile)->value;
	tmp = (*lst_pile);
	while (tmp->next)
	{
		tmp->value = tmp->next->value;
		tmp = tmp->next;
	}
	tmp->value = first_value;

}

void	ra(t_data *data)
{
	rotate_up(&data->a_pile);
	//ft_putstr_fd("ra\n", 1);
}

/*void	rb(t_data **data)
{
	if (!*data->b_pile)
		return ;
	rotate_up(data->b_pile);
}

void	rr(t_data **data)
{
	if (!(*data->a_pile) || !(*data->b_pile))
		return ;
	rotate_up(data->a_pile);
	rotate_up(data->b_pile);
}
*/