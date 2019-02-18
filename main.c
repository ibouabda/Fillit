/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:26:16 by ibouabda          #+#    #+#             */
/*   Updated: 2019/02/06 13:41:39 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	int fd;
	char **tetrim;
	int i;

	fd = open(argv[1],O_RDONLY);
	if (!(tetrim = (char**)malloc(sizeof(char*) * 26)))
		return (0);
	while (ft_readtetris(fd, tetrim[i]))
		i++;

}
