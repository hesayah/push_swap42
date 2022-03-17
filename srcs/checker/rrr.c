/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:39:24 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/17 20:36:31 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

static void	rotate_down(t_lst **lst_pile, t_data *data)
{
	t_lst		*tmp_lst;
	t_lst		*new;
	int			value;

	if (!(*lst_pile)->next)
		return ;
	tmp_lst = (*lst_pile);
	while (tmp_lst->next->next)
		tmp_lst = tmp_lst->next;
	value = tmp_lst->next->value;
	free(tmp_lst->next);
	tmp_lst->next = NULL;
	new = ft_lstnew(value);
	if (!new)
	{
		data->malloc_error = 1;
		return ;
	}
	ft_lstadd_front(lst_pile, new);
}

void	rra_checker(t_data *data)
{
	if (data->a_pile)
		rotate_down(&data->a_pile, data);
}

void	rrb_checker(t_data *data)
{
	if (data->b_pile)
		rotate_down(&data->b_pile, data);
}

void	rrr_checker(t_data *data)
{
	if (data->a_pile && data->b_pile)
	{
		rotate_down(&data->a_pile, data);
		rotate_down(&data->b_pile, data);
	}
}
