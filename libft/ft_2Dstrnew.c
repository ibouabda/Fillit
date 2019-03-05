/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2Dstrnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:51:45 by ibouabda          #+#    #+#             */
/*   Updated: 2019/03/05 14:06:45 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_2dstrnew(size_t size)
{
	char	**str;
	size_t	i;

	i = 0;
	if (!(str = (char**)malloc(sizeof(char*) * size + 1)))
	{
		return (NULL);
	}
	while (i < size + 1)
	{
		str[i] = NULL;
		i++;
	}
	return (str);
}
