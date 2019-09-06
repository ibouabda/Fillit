/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readtetris_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:29:07 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/06 12:08:01 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_verif(char *line)
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

void	ft_initialize(size_t *nl, size_t *y, size_t *ntetrim, size_t *l)
{
	*l = 0;
	*nl = 0;
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

int		ft_free_return(char **line, size_t nl)
{
	if (*line && nl % 5 == 0)
	{
		if (*line[0])
			free(*line);
	}
	return (0);
}

int		ft_readtetris_check(int fd, char ***tetrim, char ***tetrim_c)
{
	char	*line;
	size_t	y;
	size_t	l;
	size_t	nl;
	size_t	ntetrim;

	ft_initialize(&nl, &y, &ntetrim, &l);
	ft_initialize_2(tetrim, tetrim_c);
	while (++nl && get_next_line(fd, &line))
	{
		if (!line[0] && nl % 5 == 0)
		{
			free(line);
			if (!y || !(ft_new_tetrim_check(tetrim, tetrim_c, &ntetrim, &y)))
				return (0);
			if ((l = 0) == 0 && get_next_line(fd, &line))
				nl++;
		}
		if ((nl % 5 != 0 && !line[0]) || ft_strlen(line) != 4 || y > 4 || l > 4)
			return (ft_free_return(&line, nl));
		if ((tetrim_c[ntetrim][l++] = ft_strdup(line)) && ft_verif(line))
			tetrim[ntetrim][y++] = ft_strdup(line);
		free(line);
	}
	return (tetrim[0][0] != NULL && nl % 5 == 0 && y > 0);
}
