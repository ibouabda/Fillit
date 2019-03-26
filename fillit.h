/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:16:30 by ibouabda          #+#    #+#             */
/*   Updated: 2019/03/26 15:37:01 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_readtetris(int fd, char ***tetrim);
int		get_next_line(const int fd, char **line);
void	ft_erase_column(char ***tetrim);
int		ft_readtetris_check(int fd, char ***tetrim);
int		ft_check(char ***tetrim, char ***tetrim_check);
void	ft_convert_tetrim(char ***tetrim);
char	**ft_fill_square(size_t size, char ***tetrim, char **square);
char	**ft_which_square(char ***tetrim);

#endif
