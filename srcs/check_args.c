/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:47:40 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/11 14:18:51 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_arg_value(char *arg)
{
	int	i;
	int	value;

	value = ft_atoi(arg);
	if (value < INT_MIN || value > INT_MAX)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 0)
		{	
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_args(char **args)
{
	int	i;
	int	j;
	int	value_one;
	int	value_two;

	i = -1;
	while (args[++i])
	{
		if (!check_arg_value(args[i]))
			return (0);
		j = i;
		value_one = ft_atoi(args[i]);
		while (args[++j])
		{
			if (!check_arg_value(args[j]))
				return (0);
			value_two = ft_atoi(args[j]);
			if (value_one == value_two)
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
		}
	}
	return (1);
}
