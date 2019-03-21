/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:47:32 by ibouabda          #+#    #+#             */
/*   Updated: 2019/03/21 13:50:03 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	int fd;
	int fd_check;
	char ***tetrim;
	char ***tetrim_check;
	size_t i;
	size_t k;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit.out target_file");
		return (0);
	}
	fd_check = open("library.fillit", O_RDONLY);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	k = 0;
	tetrim = ft_3dstrnew(26);
	tetrim_check = ft_3dstrnew(19);
	ft_readtetris_check(fd_check, tetrim_check);
	if (!(ft_readtetris_check(fd, tetrim)))
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
	ft_3dputstr(tetrim);
}
