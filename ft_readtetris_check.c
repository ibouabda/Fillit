/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readtetris_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:29:07 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/06 09:59:45 by idris            ###   ########.fr       */
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

void	ft_initialize(size_t *nb_line, size_t *y, size_t *ntetrim, size_t *l)
{
	*l = 0;
	*nb_line = 0;
	*y = 0;
	*ntetrim = 0;
}

int		ft_new_tetrim_check(char ***tet, char ***tet_c, size_t *ntet, size_t *y)
{
	if (*ntet >= 25)
		return (0);
	*ntet += 1;
	tet[*ntet] = ft_2dstrnew(4);
	tet_c[*ntet] = ft_2dstrnew(4);
	*y = 0;
	return (1);
}

int		ft_free_return(char *line)
{
	free(line);
	return (0);
}

void ft_initialize_2(char ***tetrim, char ***tetrim_c)
{
	tetrim[0] = ft_2dstrnew(4);
	tetrim_c[0] = ft_2dstrnew(4);
}
int		ft_readtetris_check(int fd, char ***tetrim, char ***tetrim_c)
{
	char	*line;
	size_t	y;
	size_t	l;
	size_t	nb_line;
	size_t	ntetrim;

	ft_initialize(&nb_line, &y, &ntetrim, &l);
	ft_initialize_2(tetrim, tetrim_c);
	while (++nb_line && get_next_line(fd, &line))
	{
		if (!line[0] && nb_line % 5 == 0)
		{
			free(line);
			if (!y || !(ft_new_tetrim_check(tetrim, tetrim_c, &ntetrim, &y)))
				return (0);
			if ((l = 0) == 0 && get_next_line(fd, &line))
				nb_line++;
		}
		if ((!line[0] && nb_line % 5 != 0) || ft_strlen(line) != 4 || y > 4) // why 4 et l > 4 necessaire ?
			return (ft_free_return(line));
		tetrim_c[ntetrim][l++] = ft_strdup(line);
		if (ft_verif_line_check(line))
			tetrim[ntetrim][y++] = ft_strdup(line);
		free(line);
	}
	return (tetrim[0][0] != NULL && nb_line % 5 == 0 && y > 0);
}
