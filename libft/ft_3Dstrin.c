/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3Dstrin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:38:54 by retounsi          #+#    #+#             */
/*   Updated: 2019/02/20 19:19:17 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_2Dstrin(char **s1,char ***s2)
{
	size_t i;

	i = 0;
	while (s2[i])
	{
		printf("2Dstrin\n");
		if (ft_2Dstrcmp(s1, s2[i]) == 1)
			return (1);
		i++;
	}
	return(0);
}

int		ft_3Dstrin(char ***s1, char ***s2)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		printf("3Dstrin\n");
		if(ft_2Dstrin(s1[i], s2) == 0)
			return (0);
		i++;
	}
	return(1);
}
