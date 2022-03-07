/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:47:40 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/07 08:37:06 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int      check_dup(t_data *data)
{
    t_lst       *tmp_one;
    t_lst       *tmp_two;

    tmp_one = data->a_pile;
    tmp_two = tmp_one->next;
    while (tmp_one->next)
    {
        while(tmp_two->next)
        {
            if (tmp_one->value == tmp_two->value)
                return (0);
            tmp_two = tmp_two->next;
        } 
        if (tmp_one->value == tmp_two->value)
            return (0);
        tmp_one = tmp_one->next;
    }
    return (1);
}

static int     add_to_pile(t_data *data, char *arg)
{
    long    value;
    t_lst   *tmp_prev;

    value = ft_atoi(arg);
    if (value < INT_MIN || value > INT_MAX)
        return (0); 
    tmp_prev = data->a_pile;
    while (tmp_prev->next)
        tmp_prev->next;
    ft_lstadd_back(&(data->a_pile), ft_lstnew((int)value, tmp_prev));
    data->len_a++;
    return (1);
}

static  int    pars_arg(char *arg)
{
    int	i;

	i = -1;
    if ((arg[0] == '-' || arg[0] == '+') && arg[1] && ft_isdigit(arg[1]) == 1)
			i++;
	while (arg[++i])
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
    } 
    return (1);
} 

static  int    pars_main(t_data *data, char **tmp_args)
{
    int i;

    i = 0;
    while (tmp_args[i])
    {
        if (!pars_arg(tmp_args[i]))
            return (0);
        if (!add_to_pile(data, tmp_args[i]))
            return (0);
        i++;
    }
    return (1);
}

int    check_arg(t_data *data)
{
    int i;
    int ret;
    char **tmp_args;

    i = 0;
    ret = 0;
    while (data->args[i])
    {
        tmp_args = ft_split(data->args[i], " ");
        if (tmp_args[0] == NULL)
        {
            free(tmp_args);
            return (0);
        }
        ret = pars_main(data, tmp_args);
        ft_free(tmp_args);
        if (!ret)
            return (0);
        i++;
    }
    if (!check_dup(data))
        return (0);
    return (1);
}
