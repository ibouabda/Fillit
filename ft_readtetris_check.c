/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readtetris_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:29:07 by ibouabda          #+#    #+#             */
/*   Updated: 2019/03/27 17:53:36 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_verif_line_check(char *line)
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

int		ft_new_tetrim_check(char ***tet, size_t *ntet, size_t *y)
{
	if (*ntet >= 25)
		return (0);
	*ntet += 1;
	tet[*ntet] = ft_2dstrnew(4);
	*y = 0;
	return (1);
}

int		ft_readtetris_check(int fd, char ***tetrim)
{
	char	*line;
	size_t	y;
	size_t	nb_line;
	size_t	ntetrim;

	nb_line = 0;
	y = 0;
	ntetrim = 0;
	tetrim[ntetrim] = ft_2dstrnew(4);
	while (++nb_line && get_next_line(fd, &line))
	{
		if (!line[0] && nb_line % 5 == 0)
		{
			if (y == 0)
				return (0);
			if (!(ft_new_tetrim_check(tetrim, &ntetrim, &y)))
				return (0);
			if (get_next_line(fd, &line))
				nb_line++;
		}
		else if ((!line[0] && nb_line % 5 != 0)
		|| ft_strlen(line) != 4 || y > 4)
			return (0);
		if (ft_verif_line_check(line))
			tetrim[ntetrim][y++] = line;
	}
	return (tetrim[0][0] != NULL && nb_line % 5 == 0 && !line[0] && y > 0);
}
