/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:36:40 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/12 05:20:21 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_tab(int **tab, int len)
{
	int i;
	int	j;
	int value;

	i = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
		{
			if ((*tab)[i] > (*tab)[j])
			{
				value = (*tab)[i];
				(*tab)[i] = (*tab)[j];
				(*tab)[j] = value;
			}
		}
	}
}

int	get_median(t_data *data, char **args)
{
	int	i;
	int *tmp_tab;

	tmp_tab = malloc(sizeof(int) * data->len_a);
	if (!tmp_tab)
		return (0);
	i = 0;
	while (i < data->len_a)
	{
		tmp_tab[i] = atoi(args[i]);
		i++;
	}
	sort_tab(&tmp_tab, data->len_a);
	if (data->len_a % 2 == 0)
		data->median = tmp_tab[((data->len_a - 1) / 2)];
	else
		data->median = (int)((tmp_tab[(int)(data->len_a / 2)]
			+ tmp_tab[(int)((data->len_a + 1) / 2)]) / 2);
	data->max_value = tmp_tab[data->len_a - 1];
	free(tmp_tab);
	return (1);
}

void	pre_working(t_data *data)
{

	while (data->len_a > 1)
	{
		if (data->a_pile->value >= data->max_value)
			ra(data);
		else
		{
			pb(data);
			if (data->b_pile->value <= data->median)
				rb(data);
		}
	}
	//print_pile(data);
}