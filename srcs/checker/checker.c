/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:14:46 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/17 15:15:45 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

static int	do_move(t_data *data, char *input)
{
	if (ft_strncmp("pa", input, ft_strlen(input)) == 0)
		pa_checker(data);
	else if (ft_strncmp("pb", input, ft_strlen(input)) == 0)
		pb_checker(data);
	else if (ft_strncmp("sa", input, ft_strlen(input)) == 0)
		sa_checker(data);
	else if (ft_strncmp("sb", input, ft_strlen(input)) == 0)
		sb_checker(data);
	else if (ft_strncmp("ss", input, ft_strlen(input)) == 0)
		ss_checker(data);
	else if (ft_strncmp("ra", input, ft_strlen(input)) == 0)
		ra_checker(data);
	else if (ft_strncmp("rb", input, ft_strlen(input)) == 0)
		rb_checker(data);
	else if (ft_strncmp("rr", input, ft_strlen(input)) == 0)
		rr_checker(data);
	else if (ft_strncmp("rra", input, ft_strlen(input)) == 0)
		rra_checker(data);
	else if (ft_strncmp("rrb", input, ft_strlen(input)) == 0)
		rrb_checker(data);
	else if (ft_strncmp("rrr", input, ft_strlen(input)) == 0)
		rrr_checker(data);
	else
		return (0);
	return (1);
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
			break ;
		if (!do_move(data, input))
		{
			ft_putstr_fd("Error\n", 2);
			free(input);
			return (clean_up(data));
		}
		free(input);
	}
	if (ret == -1)
		return (clean_up(data));
	if (check_order(&data->a_pile))
		ft_putstr_fd("ok\n", 1);
	else
		ft_putstr_fd("ko\n", 1);
	return (clean_up(data));
}
