/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:50:07 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/11 11:32:34 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//finish

static	void	lst_delet_first(t_lst **lst, int code, t_data *data)
{
	t_lst	*ptr;

	if ((*lst)->next)
	{
		ptr = *lst;
		*lst = (*lst)->next;
		free(ptr);
	}
	else
	{
		free(*lst);
		if (!code)
			data->b_pile = NULL;
		else
			data->a_pile = NULL;
	}
}

static void	push(t_lst **lst_one, t_lst **lst_two, int code, t_data *data)
{
	t_lst		*ptr_one;
	t_lst		*ptr_two;
	t_lst		*tmp;
	int			value;
	
	ptr_two = *lst_two;
	value = ptr_two->value;
	tmp = ft_lstnew(value);
	if (tmp == NULL)
	{
		data->malloc_error = 1;
		return ;
	}
	ft_lstadd_front(lst_one, tmp);
	lst_delet_first(lst_two, code, data);
}

void	pa(t_data *data)
{
	if (data->b_pile != NULL)
	{
		push(&data->a_pile, &data->b_pile, 0, data);
		data->len_a++;
		data->len_b--;
		ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_data *data)
{
	if (data->a_pile != NULL)
	{
		push(&data->b_pile, &data->a_pile, 1, data);
		data->len_a--;
		data->len_b++;
		ft_putstr_fd("pb\n", 1);
	}
}