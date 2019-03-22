/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:08:09 by ibouabda          #+#    #+#             */
/*   Updated: 2019/03/22 11:24:37 by retounsi         ###   ########.fr       */
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
