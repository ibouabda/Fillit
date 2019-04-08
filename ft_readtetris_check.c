/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readtetris_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:29:07 by ibouabda          #+#    #+#             */
/*   Updated: 2019/04/08 15:17:40 by retounsi         ###   ########.fr       */
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
	tetrim[0] = ft_2dstrnew(4);
	while (++nb_line && get_next_line(fd, &line))
	{
		if (!line[0] && nb_line % 5 == 0)
		{
			if (!y || !(ft_new_tetrim_check(tetrim, &ntetrim, &y)))
				return (0);
			if (get_next_line(fd, &line))
				nb_line++;
		}
		else if ((!line[0] && nb_line % 5 != 0)
		|| ft_strlen(line) != 4 || y > 4)
			return (0);
		if (ft_verif_line_check(line))
		{
			if (!(tetrim[ntetrim][y] = (char*)malloc(sizeof(char*) * ft_strlen(line) + 1)))
				return (0);
			ft_strcpy(tetrim[ntetrim][y], line);
			y++;
		}
		free(line);
		ft_putnbr(nb_line);
		ft_putstr("line : ");
		ft_putendl(line);
	}
	free(line);
	return (tetrim[0][0] != NULL && nb_line % 5 == 0 && !line[0] && y > 0);
}
