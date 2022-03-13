/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:31:36 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/13 19:04:43 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->a_pile = NULL;
	data->b_pile = NULL;
	data->len_a = 0;
	data->max_value = 0;
	data->len_b = 0;
	data->malloc_error = 0;
}

void	print_pile(t_data *data)
{
	t_lst	*tmp_a;
	t_lst	*tmp_b;

	if (data->a_pile)
		tmp_a = data->a_pile;
	else
		tmp_a = NULL;
	if (data->b_pile)
		tmp_b = data->b_pile;
	else
		tmp_b = NULL;
	printf("------PILE_A----- | -----PILE_B-------\n");
	while (tmp_a || tmp_b)
	{
		/*if (!tmp_a && !tmp_b)
			break ;*/
		if (tmp_a && !tmp_b)
			printf("[%i]-------------- | ---------------[ ]\n", tmp_a->value);
		else if (!tmp_a && tmp_b)
			printf("[ ]--------------- | ---------------[%i]\n", tmp_b->value);
		else if (tmp_a && tmp_b)
			printf("[%i]-------------- | ---------------[%i]\n",
				tmp_a->value, tmp_b->value);
		if (tmp_a)	
			tmp_a = tmp_a->next;
		if (tmp_b)
			tmp_b = tmp_b->next;
	}
}

static int	free_args(char ***args, t_data *data)
{
	if (args)
		ft_free(*args);
	if (data)
		clean_up(data);
	return (0);
}

int	main(int argc, char **args)
{
	t_data	data;
	char	**new_args;

	init_data(&data);
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		new_args = ft_split(args[1], " ");
		if (new_args[0] == NULL)
		{
			ft_putstr_fd("Error\n", 2);
			return (free_args(&new_args, NULL));
		}
		if (!check_args(new_args))
			return (free_args(&new_args, NULL));
		if (!init_work(&data, new_args))
			return (free_args(&new_args, &data));
		ft_free(new_args);
	}
	else 
	{
		new_args = ++args;
		if (!check_args(new_args))
			return (free_args(NULL, NULL));
		if (!init_work(&data, new_args))
			return (free_args(NULL, &data));
	}
	//ft_putstr_fd("ENTREE\n", 1);
	//print_pile(&data);
	run(&data);
	//ft_putstr_fd("SORTIE\n", 1);
	//print_pile(&data);
	clean_up(&data);
	return (0);
}
