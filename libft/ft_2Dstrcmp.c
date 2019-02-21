/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2Dstrcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:18:54 by retounsi          #+#    #+#             */
/*   Updated: 2019/02/21 13:57:20 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_2Dstrcmp(char **s1, char **s2)
{
	size_t i;

	i = 0;
	while (s1[i])
	{
		printf("2Dstrcmp\n");
		if (ft_strcmp(s1[i], s2[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}