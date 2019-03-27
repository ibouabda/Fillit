/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_square_save.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:03:58 by ibouabda          #+#    #+#             */
/*   Updated: 2019/03/27 15:39:20 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_clear_square(char **square, char **tetrim)
{
	size_t x;
	size_t y;
	char letter;

	y = 0;
	while (tetrim[y])
	{
		while (tetrim[y][x])
		{
			x = 0;
			if (tetrim[y][x] != '.')
			{
				letter = tetrim[y][x];
				y = 0;
				while (square[y])
				{
					x = 0;
					while (square[y][x])
					{
						if (square[y][x] == letter)
							square[y][x] = '.';
						x++;
					}
					y++;
				}
				x++;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int ft_fill_tetrim(char **tetrim, char **square, size_t x, size_t y)
{
	size_t x2;
	size_t y2;
	size_t x_local;

	y2 = 0;
	while (tetrim[y2])
	{
		if (!square[y])
			return (0);
		x2 = 0;
		x_local = x;
		while (tetrim[y2][x2])
		{
			if (square[y][x_local] != '.')
				return (0);
			square[y][x_local] = tetrim[y2][x2];
			x_local++;
			x2++;
		}
		y++;
		y2++;
	}
	return (y2 == (size_t)ft_2dstrlen(tetrim) &&
			x2 == (size_t)ft_strlen(tetrim[ft_2dstrlen(tetrim) - 1]));
}

int ft_add_tetrim(size_t size, char **square, char **tetrim)
{
	size_t x;
	size_t y;
	size_t i;

	y = 0;
	i = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (ft_fill_tetrim(tetrim, square, x, y))
				return (1);
			else
				ft_clear_square(square, tetrim);
			x++;
		}
		y++;
	}
	return (0);
}

char **ft_fill_square(size_t size, char ***tetrim, char **square)
{
	size_t i;

	i = 0;
	while (tetrim[i])
	{
		if (ft_add_tetrim(size, square, tetrim[i]) == 0)
			return (0);
		i++;
	}
	return (square);
}
