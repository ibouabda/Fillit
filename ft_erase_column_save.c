/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase_column_save.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:53:54 by ibouabda          #+#    #+#             */
/*   Updated: 2019/02/07 17:14:12 by ibouabda         ###   ########.fr       */
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

void ft_change_adress(char ***tetrim, size_t ntetrim, size_t x)
{
	size_t y;

	y = 0;
	while(tetrim[ntetrim][y])
	{
		ft_memmove(tetrim[ntetrim][y],tetrim[ntetrim] + (y + 1), ft_strlen(tetrim[ntetrim][y + 1]));
	}
}

void	ft_erase_column(char ***tetrim)
{
	size_t x;
	size_t y;
	size_t ntetrim;

	x = 0;
	y = 0;
	ntetrim = 0;
	while (tetrim[ntetrim])
	{
		while (tetrim[ntetrim][y][x])
		{
			if (ft_ask_coulumn(tetrim, ntetrim, x))
			{
				ft_erase_one(tetrim, ntetrim, x);
			}
			x++;
		}
		x = 0;
		ntetrim++;
	}
}
