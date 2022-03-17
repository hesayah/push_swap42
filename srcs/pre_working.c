/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_working.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:48:03 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/16 23:18:10 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_tab(int **tab, int len)
{
	int	i;
	int	j;
	int	value;

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

static int	get_median(t_data *data, char **args)
{
	int	i;
	int	*tmp_tab;

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
		data->median = tmp_tab[((data->len_a -1) / 2)];
	else
		data->median = (int)(((int)tmp_tab[(int)((data->len_a - 1) / 2)]
					+ (int)tmp_tab[(int)((data->len_a - 1) / 2)]) / 2);
	data->min_value = tmp_tab[0];
	data->max_value = tmp_tab[data->len_a - 1];
	free(tmp_tab);
	return (1);
}

int	init_work(t_data *data, char **args)
{
	int		i;
	int		value;
	t_lst	*tmp;

	i = 0;
	while (args[i])
	{
		value = ft_atoi(args[i]);
		tmp = ft_lstnew(value);
		if (tmp == NULL)
		{
			data->malloc_error = 1;
			return (0);
		}
		ft_lstadd_back(&data->a_pile, tmp);
		data->len_a++;
		i++;
	}
	if (!get_median(data, args))
		return (0);
	return (1);
}

void	pre_working(t_data *data)
{
	while (data->len_a > 2 || !check_order(&data->a_pile))
	{
		if (data->a_pile->value == data->max_value)
			ra(data);
		else
		{
			pb(data);
			if (data->b_pile->value < data->median)
				rb(data);
		}
	}
}
