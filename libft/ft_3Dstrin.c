/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3Dstrin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:38:54 by retounsi          #+#    #+#             */
/*   Updated: 2019/02/19 16:59:43 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_2Dstrin(const char **s1, const char ***s2)
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

int		ft_3Dstrin(const char ***s1, const char ***s2)
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