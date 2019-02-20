/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3Dstrin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:38:54 by retounsi          #+#    #+#             */
/*   Updated: 2019/02/20 12:44:28 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_2Dstrin(char **s1,char ***s2)
{
	size_t i;

	i = 0;
	while (s2[i])
	{
		if (ft_2Dstrcmp(s1, s2[i]) == 0)
			return (1);
	}
	return(0);
}

int		ft_3Dstrin(char ***s1, char ***s2)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_2Dstrin(s1[i], s2))
			return (0);
		i++;
	}
	return(1);
}
