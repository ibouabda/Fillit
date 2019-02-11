/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readtetris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:29:07 by ibouabda          #+#    #+#             */
/*   Updated: 2019/02/07 13:46:19 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_verif_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '.')
			return (1);
		i++;
	}
	return (0);
}

void	ft_new_tetrim(char ***tet, size_t *ntet, char *let, size_t *y)
{
	*ntet += 1;
	tet[*ntet] = ft_2Dstrnew(4);
	*let += 1;
	*y = 0;
}

int		ft_readtetris(int fd, char ***tetrim)
{
	char	*line;
	size_t	x;
	size_t	y;
	size_t	ntetrim;
	char	letter;

	letter = 'A';
	x = 0;
	y = 0;
	ntetrim = 0;
	tetrim[ntetrim] = ft_2Dstrnew(4);
	while (get_next_line(fd, &line))
	{
		if (!line[0])
		{
			ft_new_tetrim(tetrim, &ntetrim, &letter, &y);
			get_next_line(fd, &line);
		}
		while (line[x++])
			line[x - 1] = line[x - 1] == '#' ? letter : line[x - 1];
		x = 0;
		if (ft_verif_line(line))
			tetrim[ntetrim][y++] = line;
	}
	return (1);
}
