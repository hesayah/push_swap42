/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:25:24 by hesayah           #+#    #+#             */
/*   Updated: 2021/12/23 16:19:35 by hesayah          ###   ########.fr       */
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
	t_lst		*previous;
	char		**args;
	int			len_a;
	int			len_b;
}				t_data;

int				check_arg(t_data *data);
void			run(t_data *data);
int				check_order(t_lst **lst_pile);
/*void			pa(t_data *data);
void			pb(t_data *data);*/
void		    sa(t_data *data);
/*void			sb(t_data *data);
void			ss(t_data *data);
void			ra(t_data *data);
void			rb(t_data *data);
void			rr(t_data *data);
void			rra(t_data *data);
void			rrb(t_data *data);
void			rrr(t_data *data);*/
void			clean_up(t_data *data);

#endif
