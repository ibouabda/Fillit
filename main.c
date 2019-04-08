/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:47:32 by ibouabda          #+#    #+#             */
/*   Updated: 2019/04/08 20:46:31 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_exit(char ***tetrim, char ***tetrim_check, int b)
{
	ft_3dstrdel(tetrim_check);
	ft_3dstrdel(tetrim);
	if (b == 0)
		ft_putendl("error");
	return (0);
}

int		read_final_return(char *argv)
{
	int		fd;
	int		red;
	char	*buf;

	buf = ft_strnew(4096);
	fd = open(argv, O_RDONLY);
	red = read(fd, buf, 4096);
	close(fd);
	if (buf[red - 1] == '\n')
	{
		free(buf);
		return (1);
	}
	free(buf);
	return (0);
}

int		open_files(char *argv, char ***tetrim, char ***tetrim_check)
{
	int	fd;
	int	fd_check;
	int b;

	fd_check = open("library.fillit", O_RDONLY);
	fd = open(argv, O_RDONLY);
	ft_readtetris_check(fd_check, tetrim_check);
	close(fd_check);
	b = ft_readtetris_check(fd, tetrim);
	close(fd);
	return (b && read_final_return(argv));
}

int		main(int argc, char **argv)
{
	char	***tetrim;
	char	***tetrim_check;
	char	**square;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit.out target_file");
		return (0);
	}
	tetrim = ft_3dstrnew(26);
	tetrim_check = ft_3dstrnew(19);
	if (!(open_files(argv[1], tetrim, tetrim_check)))
		return (ft_exit(tetrim, tetrim_check, 0));
	ft_erase_column(tetrim);
	ft_erase_column(tetrim_check);
	if (!ft_check(tetrim, tetrim_check))
		return (ft_exit(tetrim, tetrim_check, 0));
	ft_convert_tetrim(tetrim);
	square = ft_which_square(tetrim);
	ft_2dputstr(square);
	ft_2dstrdel(square);
	return (ft_exit(tetrim, tetrim_check, 1));
}
