/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 11:35:59 by ibouabda          #+#    #+#             */
/*   Updated: 2019/01/29 19:32:13 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 10
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef	struct		s_prlist
{
	char			*content;
	int				fd;
	struct s_prlist	*next;
	struct s_prlist	*prev;
}					t_prlist;

int					get_next_line(const int fd, char **line);

#endif
