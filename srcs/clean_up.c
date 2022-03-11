/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 18:20:38 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/10 23:11:06 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lst_free(t_lst **lst_pile)
{
	t_lst		*lst;
	t_lst		*tmp;

	//printf("clean up entree == [%p]\n", lst_pile);
	lst = *lst_pile;
	while (lst)
	{	
		tmp = lst;
		lst = lst->next;
		free(tmp);
		tmp = NULL;
	}
	//printf("clean up sortie == [%p]\n", lst_pile);
}

void	clean_up(t_data *data)
{
	if (data->a_pile)
		ft_lst_free(&data->a_pile);
	if (data->b_pile)
		ft_lst_free(&data->b_pile);
}
