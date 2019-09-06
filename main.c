/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:47:32 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/06 10:32:49 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_exit(char ***tetrim, char ***tetrim_check, int b)
{
	ft_3dstrdel(tetrim_check);
	ft_3dstrdel(tetrim);
	if (b == 0)
		ft_putendl("error");
	while(1);
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
	int fd_dir;
	int b;

	fd = open(argv, O_RDONLY);
	fd_dir = open(argv, O_DIRECTORY);
	if (fd == -1 || fd_dir > 0)
	{
		close(fd_dir);
		close(fd);
		return (0);
	}
	close(fd_dir);
	if (!(b = ft_readtetris_check(fd, tetrim, tetrim_check)))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (b && read_final_return(argv));
}

int		main(int argc, char **argv)
{
	char	***tetrim;
	char	***tetrim_check;
	char	**square;

	tetrim = ft_3dstrnew(26);
	tetrim_check = ft_3dstrnew(26);
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit target_file");
		return (0);
	}
	if (!(open_files(argv[1], tetrim, tetrim_check)))
		return (ft_exit(tetrim, tetrim_check, 0));
	ft_erase_column(tetrim);
	if (!ft_check(tetrim_check))
		return (ft_exit(tetrim, tetrim_check, 0));
	ft_convert_tetrim(tetrim);
	square = ft_which_square(tetrim);
	ft_2dputstr(square);
	ft_2dstrdel(square);
	return (ft_exit(tetrim, tetrim_check, 1));
}
