/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:31:36 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/07 08:14:30 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		init_data(t_data *data, char **args)
{
	int i;
	
	i = 0;
	data->a_pile = NULL;
	data->b_pile = NULL;
	data->args = ++args;
	data->len_a = 0;
	data->len_b = 0;
}

int			main(int argc, char **args)
{
	int		i;
	int		ret;
	t_data	data;

	if (argc == 1)
		return (0);
	init_data(&data, args);
	ret = check_arg(&data);
	if (!ret)
		ft_putstr_fd("Error\n", 2);
	else
		run(&data);
	//clean_up(&data);
	//system("leaks push_swap");
	printf("len_a == [%i]\n", data.len_a);
	return (0);
}
