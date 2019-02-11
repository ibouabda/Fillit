/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:26:16 by ibouabda          #+#    #+#             */
/*   Updated: 2019/02/07 16:58:21 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	int		fd;
	char	***tetrim;
	size_t	i;
	size_t	k;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	i = 0;
	k = 0;
	tetrim = ft_3Dstrnew(26);
	ft_readtetris(fd, tetrim);
	ft_erase_column(tetrim);
	while (tetrim[i])
	{
		while(tetrim[i][k])
		{
			printf("%s\n",tetrim[i][k]);
			k++;
		}
		printf("\n");
		i++;
		k = 0;
	}
}
