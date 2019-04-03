/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:47:32 by ibouabda          #+#    #+#             */
/*   Updated: 2019/04/03 18:28:03 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		open_files(char *argv, char ***tetrim, char ***tetrim_check)
{
	int	fd;
	int	fd_check;

	fd_check = open("library.fillit", O_RDONLY);
	fd = open(argv, O_RDONLY);
	ft_readtetris_check(fd_check, tetrim_check);
	return (ft_readtetris_check(fd, tetrim));
}

int		main(int argc, char **argv)
{
	char	***tetrim;
	char	***tetrim_check;
	char	**square;
	int i;

	i = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit.out target_file");
		return (0);
	}
	tetrim = ft_3dstrnew(26);
	tetrim_check = ft_3dstrnew(19);
	if (!(open_files(argv[1], tetrim, tetrim_check)))
	{
		ft_3dputstr(tetrim);
		ft_putendl("error read tetris check");
		return (0);
	}
	ft_erase_column(tetrim);
	ft_erase_column(tetrim_check);
	if (!ft_check(tetrim, tetrim_check))
	{
		ft_putendl("error");
		return (0);
	}
	ft_convert_tetrim(tetrim);
	square = ft_which_square(tetrim);
	ft_2dputstr(square);
	ft_2dstrdel(square);
	/*while (1 == 1)
		i++;
*/
	/*char *line;
	int	fd_check;

	fd_check = open("library.fillit", O_RDONLY);
	while (get_next_line(fd_check, &line))
	{
		ft_putendl(line);
		free(line);
	}*/
	return (0);
}
