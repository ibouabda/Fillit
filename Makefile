# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 17:46:29 by idris             #+#    #+#              #
#    Updated: 2019/02/20 18:59:37 by ibouabda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit.out

CFLAGS = -Wall -Werror -Wextra

PATHFILE = ./libft

CC = gcc

SRC_NAME = get_next_line.c ft_readtetris.c ft_erase_column.c\
			ft_readtetris_check.c ft_check.c main.c

OBJ_NAME = $(SRC_NAME:.c=.o)

all: .libft $(NAME)

.libft:
	make -C $(PATHFILE)

$(NAME): $(OBJ_NAME)
	$(CC) $(CFLAGS) -c $(SRC_NAME)
	$(CC) -o $(NAME) $(OBJ_NAME) libft/libft.a

clean:
	rm -f $(OBJ_NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
