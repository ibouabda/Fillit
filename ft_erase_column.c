/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase_column.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:53:54 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/06 09:23:03 by idris            ###   ########.fr       */
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

int		ft_nbor(char ***tetrim_c, int ntetrim, int y, int x)
{
	int nbor;

	nbor = 0;
	if (x - 1 >= 0 && tetrim_c[ntetrim][y][x - 1] == '#')
		nbor++;
	if (x + 1 < 4 && tetrim_c[ntetrim][y][x + 1] == '#')
		nbor++;
	if (y - 1 >= 0 && tetrim_c[ntetrim][y - 1][x] == '#')
		nbor++;
	if (y + 1 < 4 && tetrim_c[ntetrim][y + 1][x] == '#')
		nbor++;
	return (nbor);
}

void	ft_counter(char ***tetrim_c, int ntetrim, int *nbor, int *count)
{
	int y;
	int x;

	y = 0;
	*nbor = 0;
	*count = 0;
	while (tetrim_c[ntetrim][y] && y < 4)
	{
		x = 0;
		while (tetrim_c[ntetrim][y][x] && x < 4)
		{
			if (tetrim_c[ntetrim][y][x] == '#')
			{
				*nbor += ft_nbor(tetrim_c, ntetrim, y, x);
				*count = *count + 1;
			}
			x++;
		}
		y++;
	}
}

int		ft_check(char ***tetrim_c)
{
	int count;
	int nbor;
	int ntetrim;

	ntetrim = 0;
	while (tetrim_c[ntetrim])
	{
		ft_counter(tetrim_c, ntetrim, &nbor, &count);
		if (!(nbor >= 6 && count == 4))
			return (0);
		ntetrim++;
	}
	return (1);
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
