/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:25:24 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/11 11:28:58 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "limits.h"
#include "../libft/libft.h"

typedef struct	s_data
{	
	t_lst		*a_pile;
	t_lst		*b_pile;
	int			len_a;
	int			len_b;
	int			median_a;
	int			median_b;
	int			malloc_error;
}				t_data;

int				check_args(char **args);
int				run(t_data *data);
int				check_order(t_lst **lst_pile);
void			print_pile(t_data *data);
void			pa(t_data *data);
void			pb(t_data *data);
void		    sa(t_data *data);
void			sb(t_data *data);
void			ss(t_data *data);
void			ra(t_data *data);
void			rb(t_data *data);
void			rr(t_data *data);
void			rra(t_data *data);
void			rrb(t_data *data);
void			rrr(t_data *data);
void			clean_up(t_data *data);

#endif
