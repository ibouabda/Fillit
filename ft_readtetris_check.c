/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readtetris_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:29:07 by ibouabda          #+#    #+#             */
/*   Updated: 2019/02/19 15:52:19 by retounsi         ###   ########.fr       */
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

int		ft_new_tetrim(char ***tet, size_t *ntet, char *let, size_t *y)
{
	if (*ntet >= 25)
		return (0);
	*ntet += 1;
	tet[*ntet] = ft_2Dstrnew(4);
	*let += 1;
	*y = 0;
	return (1);
}

int		ft_readtetris_check(int fd, char ***tetrim)
{
	char	*line;
	size_t	x;
	size_t	y;
	size_t	ntetrim;
	char	letter;

	letter = 'A';
	y = 0;
	ntetrim = 0;
	tetrim[ntetrim] = ft_2Dstrnew(4);
	while (get_next_line(fd, &line))
	{
		if (!line[0])
		{
			if (!(ft_new_tetrim(tetrim, &ntetrim, &letter, &y)))
				return (0);
			get_next_line(fd, &line);
		}
		x = 0;
		if (ft_verif_line(line))
			tetrim[ntetrim][y++] = line;
	}
	return (1);
}
