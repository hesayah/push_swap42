/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:31:36 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/17 19:49:24 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	init_data(t_data *data)
{
	data->a_pile = NULL;
	data->b_pile = NULL;
	data->len_a = 0;
	data->max_value = 0;
	data->len_b = 0;
	data->malloc_error = 0;
}

static int	free_args(char ***args, t_data *data)
{
	if (args)
		ft_free(*args);
	if (data)
		clean_up(data);
	return (0);
}

static int	one_input_args(char **args, t_data *data)
{
	char	**new_args;

	new_args = ft_split(args[1], " ");
	if (!new_args)
		return (0);
	if (new_args[0] == NULL)
		return (free_args(&new_args, NULL));
	if (!check_args(new_args))
		return (free_args(&new_args, NULL));
	if (!init_work(data, new_args))
		return (free_args(&new_args, data));
	ft_free(new_args);
	return (1);
}

int	main(int argc, char **args)
{
	char	**new_args;
	t_data	data;

	init_data(&data);
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		if (!one_input_args(args, &data))
			return (0);
	}
	else
	{
		new_args = ++args;
		if (!check_args(new_args))
			return (free_args(NULL, NULL));
		if (!init_work(&data, new_args))
			return (free_args(NULL, &data));
	}
	return (run(&data));
}
