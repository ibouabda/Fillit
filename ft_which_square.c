/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:08:09 by ibouabda          #+#    #+#             */
/*   Updated: 2019/04/08 20:24:36 by retounsi         ###   ########.fr       */
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

size_t	*ft_find_tetrim(char **square, char letter, char **tetrim)
{
	size_t	x;
	size_t	y;
	int		i;
	size_t	*tab;

	i = 0;
	while (tetrim[0][i] == '.')
		i++;
	y = -1;
	tab = ft_memalloc(16);
	while (square[++y])
	{
		x = -1;
		while (square[y][++x])
		{
			if (square[y][x] == letter)
			{
				tab[0] = y;
				tab[1] = x - i;
				return (tab);
			}
		}
	}
	free(tab);
	return (0);
}

void	ft_clear_tetrim(char **square, size_t ntet)
{
	size_t	x;
	size_t	y;
	char	letter;

	y = 0;
	letter = 'A' + ntet;
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

	size = ft_sqrt_aprox(ft_3dstrlen(tetrim) * 4);
	while (size <= 16)
	{
		i = 0;
		square = ft_2dstrnew(size);
		while (i < size)
			square[i++] = ft_strnew(size);
		ft_fill_point(square, size);
		if (ft_fill_square(size, tetrim, square))
			return (square);
		ft_2dstrdel(square);
		size++;
	}
	return (NULL);
}
