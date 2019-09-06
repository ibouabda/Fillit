/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:27:27 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/06 10:29:50 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_initialize_2(char ***tetrim, char ***tetrim_c)
{
	tetrim[0] = ft_2dstrnew(4);
	tetrim_c[0] = ft_2dstrnew(4);
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
