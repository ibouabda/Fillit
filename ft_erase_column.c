/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase_column.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:53:54 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/03 11:04:38 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_ask_coulumn(char ***tetrim, size_t ntetrim, size_t x)
{
	size_t y;

	y = 0;
	while (tetrim[ntetrim][y])
	{
		if (tetrim[ntetrim][y][x] != '.')
			return (0);
		y++;
	}
	return (1);
}

void	ft_erase_one(char ***tetrim, size_t ntetrim, size_t x)
{
	size_t y;

	y = 0;
	while (tetrim[ntetrim][y])
	{
		tetrim[ntetrim][y][x] = '\0';
		y++;
	}
}

void	ft_shift(char ***tetrim)
{
	size_t	ntetrim;
	size_t	x;
	size_t	y;
	char	*todel;

	y = 0;
	x = 0;
	ntetrim = 0;
	while (tetrim[ntetrim])
	{
		while (tetrim[ntetrim][y] && y < 4)
		{
			while (tetrim[ntetrim][y][x] == '\0' && x < 4)
				x++;
			todel = tetrim[ntetrim][y] + x;
			tetrim[ntetrim][y] = ft_strdup(todel);
			todel = todel - x;
			free(todel);
			x = 0;
			y++;
		}
		y = 0;
		ntetrim++;
	}
}

int		ft_check(char ***tetrim, char ***tetrim_check)
{
	return (ft_3dstrin(tetrim, tetrim_check));
}

void	ft_erase_column(char ***tetrim)
{
	size_t x;
	size_t ntetrim;

	x = 0;
	ntetrim = 0;
	while (tetrim[ntetrim])
	{
		while (tetrim[ntetrim][0][x])
		{
			if (ft_ask_coulumn(tetrim, ntetrim, x))
				ft_erase_one(tetrim, ntetrim, x);
			x++;
		}
		x = 0;
		ntetrim++;
	}
	ft_shift(tetrim);
}
