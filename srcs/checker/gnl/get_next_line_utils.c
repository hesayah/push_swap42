/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:49:41 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/17 13:48:40 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/checker.h"

size_t	ft_check(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_checklen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
