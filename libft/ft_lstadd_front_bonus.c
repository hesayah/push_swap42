/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:55:44 by hesayah           #+#    #+#             */
/*   Updated: 2021/12/11 05:18:14 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_lst **alst, t_lst *new)
{
	void	*tmp;

	if (!alst || !new)
		return ;
	tmp = new;
	new->next = *alst;
	*alst = tmp;
}
