/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:03:58 by ibouabda          #+#    #+#             */
/*   Updated: 2019/03/22 12:15:06 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_add_tetrim(size_t size, char **square, char ***tetrim)
{
	size_t x;
	size_t y;
	size_t i;

	x = 0;
	y = 0;
	while (y < size)
	{
		while (x < size)
		{
			x++;
			if (ft_tetrim_fill(size, square, ***tetrim))
				i++;
			else
				return (0);
		}
		y++;
	}
}

char	**ft_fill_square(size_t size, char ***tetrim)
{
	char	**square;
	size_t	i;

	i = 0;
	square = ft_2dstrnew(size);
	while (i < size)
	{
		square[size] = ft_strnew(size);
		i++;
	}
	i = 0;
	while (tetrim[i])
	{
		ft_add_tetrim(size, square, tetrim[i]);
		i++;
	}
	return (square);
}
