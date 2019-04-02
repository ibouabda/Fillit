/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:47:32 by ibouabda          #+#    #+#             */
/*   Updated: 2019/04/02 19:55:01 by ibouabda         ###   ########.fr       */
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

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit.out target_file");
		return (0);
	}
	tetrim = ft_3dstrnew(26);
	tetrim_check = ft_3dstrnew(19);
	if (!(open_files(argv[1], tetrim, tetrim_check)))
	{
		ft_putendl("error");
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
	ft_2dputstr(ft_which_square(tetrim));
	return (0);
}
