/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:25:24 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/11 01:40:58 by hesayah          ###   ########.fr       */
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
}				t_data;

int				check_args(char **args);
int				run(t_data *data);
int				check_order(t_lst **lst_pile);
void			print_pile(t_lst **pile);
void			pa(t_data *data);
void			pb(t_data *data);
/*void		    sa(t_lst **a_pile, t_lst **b_pile);
void			sb(t_lst **a_pile, t_lst **b_pile);
void			ss(t_lst **a_pile, t_lst **b_pile);*/
void			ra(t_data *data);
/*void			rb(t_lst **a_pile, t_lst **b_pile);
void			rr(t_lst **a_pile, t_lst **b_pile);
void			rra(t_lst **a_pile, t_lst **b_pile);
void			rrb(t_lst **a_pile, t_lst **b_pile);
void			rrr(t_lst **a_pile, t_lst **b_pile);*/
void			clean_up(t_data *data);

#endif
