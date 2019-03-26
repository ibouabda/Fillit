/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:03:58 by ibouabda          #+#    #+#             */
/*   Updated: 2019/03/26 14:50:14 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fill_point(char **square, size_t size)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	while (y < size)
	{
		while (x < size)
		{
			square[y][x] = '.';
			x++;
		}
		y++;
		x = 0;
	}
}

int ft_fill_tetrim(char **tetrim, char **square, size_t x, size_t y)
{
	size_t x2;
	size_t y2;

	x2 = 0;
	y2 = 0;
	while (tetrim[y2] && square[y])
	{
		x2 = 0;
		x = 0;
		while (tetrim[y2][x2] && square[y][x])
		{
			square[y][x] = tetrim[y2][x2];
			x++;
			x2++;
		}
		y++;
		y2++;
	}
	return (y2 == (size_t)ft_2dstrlen(tetrim) &&
	 x2 == (size_t)ft_strlen(tetrim[ft_2dstrlen(tetrim) - 1]));
}

int		ft_add_tetrim(size_t size, char **square, char **tetrim)
{
	size_t x;
	size_t y;
	size_t i;

	x = 0;
	y = 0;
	i = 0;
	while (y < size)
	{
		while (x < size)
		{
			if (ft_fill_tetrim(tetrim, square, x, y))
				return(1);
			x++;
		}
		y++;
	}
	return (0);
}

char	**ft_fill_square(size_t size, char ***tetrim)
{
	char	**square;
	size_t	i;

	i = 0;
	square = ft_2dstrnew(size);
	while (i < size)
	{
		square[i] = ft_strnew(size);
		i++;
	}
	ft_fill_point(square, size);
	i = 0;
	//printf("ft_3dstrlen : %i\n", ft_3dstrlen(tetrim));
	while (tetrim[i])
	{
		ft_add_tetrim(size, square, tetrim[i]);
		i++;
	}
	return (square);
}
