/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:03:58 by ibouabda          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/03/26 11:15:08 by ibouabda         ###   ########.fr       */
=======
/*   Updated: 2019/03/22 12:20:50 by retounsi         ###   ########.fr       */
>>>>>>> 660915bd212cfd95f53dde602bada3f3a5ca34ab
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
		while (square[y][x])
		{
			square[y][x] = '.';
			x++;
		}
		y++;
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
		while (tetrim[y2][x2] && square[y][x])
		{
			square[y][x] = tetrim[y2][x2];
			x++;
			x2++;
		}
		y++;
		y2++;
	}
	return (y2 == ft_2dstrlen(tetrim) - 1 &&
	 x2 == ft_strlen(tetrim[ft_2dstrlen(tetrim) - 1]));
}


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
			if (ft_fill_tetrim(tetrim[i], square, x, y))
				i++;
			else
				return (0);
			x++;
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
