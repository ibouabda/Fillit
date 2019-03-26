/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:08:09 by ibouabda          #+#    #+#             */
/*   Updated: 2019/03/26 14:50:16 by ibouabda         ###   ########.fr       */
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

char	**ft_which_square(char ***tetrim)
{
	int size;
	char **square;

	size = ft_sqrt(ft_3dstrlen(tetrim) * 4);
	while (size <= 16)
	{
		if ((square = ft_fill_square(size, tetrim)))
			return (square);
		size++;
	}
	return (0);
}
