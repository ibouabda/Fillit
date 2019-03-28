/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:08:09 by ibouabda          #+#    #+#             */
/*   Updated: 2019/03/27 16:33:12 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_convert_tetrim(char ***tetrim)
{
	size_t	ntetrim;
	size_t	y;
	size_t	x;
	char	letter;

	letter = 'A' - 1;
	y = 0;
	x = 0;
	ntetrim = 0;
	while (tetrim[ntetrim] && letter++)
	{
		while (tetrim[ntetrim][y])
		{
			while (tetrim[ntetrim][y][x])
			{
				if (tetrim[ntetrim][y][x] == '#')
					tetrim[ntetrim][y][x] = letter;
				x++;
			}
			y++;
			x = 0;
		}
		y = 0;
		ntetrim++;
	}
}

void	ft_fill_point(char **square, size_t size)
{
	size_t	x;
	size_t	y;

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

char	**ft_which_square(char ***tetrim)
{
	size_t	size;
	char	**square;
	size_t	i;

	size = ft_sqrt(ft_3dstrlen(tetrim) * 4);
	while (size <= 16)
	{
		i = 0;
		square = ft_2dstrnew(size);
		while (i < size)
		{
			square[i] = ft_strnew(size);
			i++;
		}
		ft_fill_point(square, size);
		if ((square = ft_fill_square(size, tetrim, square)))
			return (square);
		size++;
	}
	return (NULL);
}
