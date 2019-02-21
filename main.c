/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:26:16 by ibouabda          #+#    #+#             */
/*   Updated: 2019/02/21 17:58:16 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	int fd;
	int fd_check;
	char ***tetrim;
	char ***tetrim_check;
	char *test;
	size_t i;
	size_t k;

	if (argc != 2)
	{
		ft_putstr("Error Arguments\n");
		return(0);
	}
	fd_check = open("library.fillit", O_RDONLY);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i < 5)
	{
		get_next_line(fd, &test);
		i++;
	}
	i = 0;
	k = 0;
	tetrim = ft_3Dstrnew(26);
	tetrim_check = ft_3Dstrnew(19);
	ft_readtetris_check(fd_check, tetrim_check);
	if (test[0] == '\0')
	{
		if (!(ft_readtetris_check(fd, tetrim)))
		{
			ft_putendl("Error number of tetriminos");
			return(0);
		}
		if (tetrim[0][0])
		{
			ft_erase_column(tetrim);
			ft_erase_column(tetrim_check);
		}
	}
	else
	{
		ft_putendl("Tetriminos non valide !");
		return (0);
	}
	if (!ft_check(tetrim, tetrim_check))
	{
		ft_putstr("Tetriminos non valide !\n");
		return (0);
	}
	printf("tetrim : \n\n");
	ft_3Dputstr(tetrim);
}
