/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3Dstrin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:38:54 by retounsi          #+#    #+#             */
/*   Updated: 2019/02/21 16:23:26 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_2Dstrin(char **s1,char ***s2) //compare le tetrim avec la libtetrim
{
	size_t i;

	i = 0;
	while (s2[i])
	{
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
		if(ft_2Dstrin(s1[i], s2) == 0)
			return (0);
		i++;
	}
	return(1);
}
