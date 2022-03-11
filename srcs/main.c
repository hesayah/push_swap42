/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:31:36 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/11 01:24:44 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int		init_work(t_data *data, char **args)
{
	int		i;
	int		value;
	t_lst	*tmp;

	i = 0;
	while (args[i])
	{
		value = ft_atoi(args[i]);
		tmp = ft_lstnew(value);
		ft_lstadd_back(&data->a_pile, tmp);
		data->len_a++;
		i++;
	}
	return (1);
}

static void		init_data(t_data *data)
{
	int i;
	
	i = 0;
	data->a_pile = NULL;
	data->b_pile = NULL;
	data->len_a = 0;
	data->len_b = 0;
}

void		print_pile(t_lst **pile)
{
	t_lst *tmp;

	tmp = *pile;
	ft_putstr_fd("\n---------------------\n", 1);
	while (tmp)
	{
		printf("value==[%i]\n", tmp->value);
		tmp = tmp->next;
	}
	ft_putstr_fd("\n---------------------\n", 1);

}

static int	free_args(char ***args)
{
	ft_free(*args);
	return (0);
}

int			main(int argc, char **args)
{
	t_data	data;
	char	**new_args;

	init_data(&data);
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		new_args = ft_split(args[1], " ");
		if (!check_args(new_args))
			return (free_args(&args));
		if (!init_work(&data, new_args))
			return (free_args(&args));
		ft_free(new_args);
	}
	else
	{
		new_args = ++args;
		if (!check_args(new_args))
			return (0);
		if (!init_work(&data, new_args))
			return (0);
	}
	ft_putstr_fd("ENTREE\n", 1);
	print_pile(&data.a_pile);
	run(&data);
	ft_putstr_fd("SORTIE\n", 1);
	print_pile(&data.a_pile);
	clean_up(&data);
	return (0);
}
