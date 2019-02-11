/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:16:30 by ibouabda          #+#    #+#             */
/*   Updated: 2019/02/07 12:29:50 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
#include <stdio.h>
# include "libft/libft.h"

int ft_readtetris(int fd, char ***tetrim);
int	get_next_line(const int fd, char **line);
void ft_erase_column(char ***tetrim);

#endif
