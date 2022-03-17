/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:17:11 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/17 15:23:19 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 4
# include "../include/push_swap.h"

int		checker(t_data *data);
int		get_next_line(int fd, char **line);
size_t	ft_check(char *str);
size_t	ft_checklen(char *str);
char	*ft_res(char *res);
char	*ft_start(char *res, int fd);
char	*ft_res2(int ret, char *res, char *buff);
void	pa_checker(t_data *data);
void	pb_checker(t_data *data);
void	sa_checker(t_data *data);
void	sb_checker(t_data *data);
void	ss_checker(t_data *data);
void	ra_checker(t_data *data);
void	rb_checker(t_data *data);
void	rr_checker(t_data *data);
void	rra_checker(t_data *data);
void	rrb_checker(t_data *data);
void	rrr_checker(t_data *data);

#endif