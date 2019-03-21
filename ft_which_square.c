/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:08:09 by ibouabda          #+#    #+#             */
/*   Updated: 2019/03/21 15:41:24 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_convert_tetrim(char ***tetrim)
{
	size_t	ntetrim;
	size_t	y;
	size_t	x;
	char	letter;

	letter = 'A';
	y = 0;
	x = 0;
	ntetrim = 0;
	while (tetrim[ntetrim])
	{
		while (tetrim[ntetrim][y])
		{
			while (tetrim[ntetrim][y][x])
			{
				if (tetrim[ntetrim][y][x] == '#')
					tetrim[ntetrim][y][x] = letter;
				x++;
			}
			x = 0;
			y++;
		}
		y = 0;
		letter++;
		ntetrim++;
	}
}

int		ft_which_square(char ***tetrim)
{
	int size;

	size = ft_sqrt(ft_2dstrlen(*tetrim) * 4);
	
	while (size <= 16)
	{
		if (ft_fill_square(size, tetrim))
			return (1);
		size++;
	}
	return (0);
}
