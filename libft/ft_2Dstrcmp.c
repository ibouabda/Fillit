/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2Dstrcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:18:54 by retounsi          #+#    #+#             */
/*   Updated: 2019/02/21 16:30:58 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_2Dstrcmp(char **s1, char **s2)
{
	size_t i;

	i = 0;
	while (s1[i])
	{
		if (s2[i])
		{
			if (ft_strcmp(s1[i], s2[i]) != 0)
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}
