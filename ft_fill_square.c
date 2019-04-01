/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:03:58 by ibouabda          #+#    #+#             */
/*   Updated: 2019/04/01 16:44:51 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fill_tetrim(char **tetrim, char **square, size_t x, size_t y)
{
	size_t	x2;
	size_t	y2;
	size_t	x_local;

	y2 = -1;
	while (tetrim[++y2] && square[y])
	{
		x2 = 0;
		x_local = x;
		while (tetrim[y2][x2])
		{
			while (tetrim[y2][x2++] == '.')
				x_local++;
			x2--;
			if (!tetrim[y2][x2])
				break ;
			if (square[y][x_local] != '.')
				return (0);
			square[y][x_local++] = tetrim[y2][x2++];
		}
		y++;
	}
	return (y2 == (size_t)ft_2dstrlen(tetrim) &&
			x2 == (size_t)ft_strlen(tetrim[ft_2dstrlen(tetrim) - 1]));
}

int		ft_add_tetrim(size_t size, char **square, char **tetrim, size_t ntet)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (ft_fill_tetrim(tetrim, square, x, y))
				return (1);
			else
				ft_clear_tetrim(square, ntet);
			x++;
		}
		y++;
	}
	return (0);
}

int		ft_reorganize(char **square,char **tetrim, int i, size_t size)
{
	size_t *tab;

	if ((tab = ft_find_tetrim(square, 'A' + i)))
	{
		tab[1]++;
		ft_clear_tetrim(square, i);
	}
	else
	{
		tab = ft_memalloc(16);
		tab[0] = 0;
		tab[1] = 0;
	}
	while (tab[0] < size)
	{
		while (tab[1] < size)
		{
			if (ft_fill_tetrim(tetrim, square, tab[1], tab[0]))
				return (1);
			else
				ft_clear_tetrim(square, i);
			tab[1]++;
		}
		tab[0]++;
		tab[1] = 0;
	}
	return (0);
}

char	**ft_fill_square(size_t size, char ***tetrim, char **square)
{
	int	i;

	i = 0;
	while (tetrim[i])
	{
		if (ft_reorganize(square, tetrim[i], i, size))
			i++;
		else
			i--;
		ft_2dputstr(square);
	}
	if (i >= 0)
		return (square);
	else
		return (0);
}
 