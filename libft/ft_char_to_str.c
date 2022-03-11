/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 09:13:32 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/11 14:12:40 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_char_to_str(char c)
{
	char	*dst;

	dst = malloc(sizeof(char) * 2);
	if (dst == NULL)
		return (NULL);
	dst[0] = c;
	dst[1] = '\0';
	return (dst);
}
