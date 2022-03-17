/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:14:46 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/17 19:52:07 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

static void	do_move(t_data *data, char **input)
{
	if (ft_strncmp("pa", *input, 3) == 0)
		pa_checker(data);
	else if (ft_strncmp("pb", *input, 3) == 0)
		pb_checker(data);
	else if (ft_strncmp("sa", *input, 3) == 0)
		sa_checker(data);
	else if (ft_strncmp("sb", *input, 3) == 0)
		sb_checker(data);
	else if (ft_strncmp("ss", *input, 3) == 0)
		ss_checker(data);
	else if (ft_strncmp("ra", *input, 3) == 0)
		ra_checker(data);
	else if (ft_strncmp("rb", *input, 3) == 0)
		rb_checker(data);
	else if (ft_strncmp("rr", *input, 3) == 0)
		rr_checker(data);
	else if (ft_strncmp("rra", *input, 4) == 0)
		rra_checker(data);
	else if (ft_strncmp("rrb", *input, 4) == 0)
		rrb_checker(data);
	else if (ft_strncmp("rrr", *input, 4) == 0)
		rrr_checker(data);
	free(*input);
}

int	checker(t_data *data)
{
	int		ret;
	t_lst	*ptr_a;
	char	*input;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &input);
		if (input[0] == '\0')
		{
			free(input);
			break ;
		}
		do_move(data, &input);
	}
	if (check_order(&data->a_pile))
		ft_putstr_fd("ok\n", 1);
	else
		ft_putstr_fd("ko\n", 1);
	return (clean_up(data));
}
