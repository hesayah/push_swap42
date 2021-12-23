/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:50:07 by hesayah           #+#    #+#             */
/*   Updated: 2021/12/23 16:43:28 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	lst_delet_first(t_lst **lst, t_data *data, int code)
{
	t_lst	*ptr;

	ptr = (*lst);
	if (ptr->next)
	{	
		if (code)
			data->a_pile = ptr->next;
		else
			data->b_pile = ptr->next;
		free(ptr);
	}
	else
	{
		free(ptr);
		if (code)
			data->a_pile = NULL;
		else
			data->b_pile = NULL;
	}
}

static void	push(t_lst **lst_one, t_lst **lst_two, t_data *data, int code)
{
	t_lst		*ptr_one;
	t_lst		*ptr_two;
	t_lst		*ptr_tmp;
	int			value;
	
	if (!lst_two)
		return ;
	ptr_two = *lst_two;
	value = ptr_two->value;
	ptr_tmp = ft_lstnew(value, NULL);
	ft_lstadd_front(lst_one, ptr_tmp);
	ptr_one = *lst_one;
	ptr_one->previous = NULL;
	while (ptr_one->next)
		ptr_one = ptr_one->next;
	ptr_one->next = NULL;
	lst_delet_first(lst_two, data, code);
}

void	pa(t_data *data)
{
	if (data->b_pile)
		push(&data->a_pile, &data->b_pile, data, 0);

}

void	pb(t_data *data)
{
	if (data->a_pile)
		push(&data->b_pile, &data->a_pile, data, 1);
}