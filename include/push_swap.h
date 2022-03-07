/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:25:24 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/07 08:46:22 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "limits.h"
#include "../libft/libft.h"

typedef struct	s_data
{	
	t_lst		**a_pile;
	t_lst		**b_pile;
	char		**args;
	int			len_a;
	int			len_b;
}				t_data;

int				check_arg(t_data *data);
/*void			run(t_data *data);
int				check_order(t_lst **lst_pile);
void			pa(t_lst *a_pile);
void			pb(t_lst *b_pile);
void		    sa(t_lst *a_pile);
void			sb(t_lst *b_pile);
void			ss(t_piles *pile, t_lst *b_pile);
void			ra(t_lst *a_pile);
void			rb(t_lst *b_pile);
void			rr(t_piles *pile, t_lst *b_pile);
void			rra(t_lst *a_pile);
void			rrb(t_lst *b_pile);
void			rrr(t_lst *a_pile, t_lst *b_pile);*/
void			clean_up(t_data *data);

#endif
