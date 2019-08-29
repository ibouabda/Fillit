/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dstrnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:51:45 by ibouabda          #+#    #+#             */
/*   Updated: 2019/08/26 15:37:02 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_2dstrnew(size_t size)
{
	char	**str;
	size_t	i;

	i = 0;
	if (!(str = (char**)malloc(sizeof(char*) * size + 1)))
	{
		ft_putendl("ft_2dstrnew malloc error");
		exit(EXIT_FAILURE);
	}
	while (i < size + 1)
	{
		str[i] = NULL;
		i++;
	}
	return (str);
}
