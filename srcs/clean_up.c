/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 18:20:38 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/13 20:19:00 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lst_free(t_lst **lst_pile)
{
	t_lst		*lst;
	t_lst		*tmp;

	lst = *lst_pile;
	while (lst)
	{	
		tmp = lst;
		lst = lst->next;
		free(tmp);
		tmp = NULL;
	}
}

int	clean_up(t_data *data)
{
	if (data->a_pile)
		ft_lst_free(&data->a_pile);
	if (data->b_pile)
		ft_lst_free(&data->b_pile);
	return (0);
}
