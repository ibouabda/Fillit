# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 17:46:29 by idris             #+#    #+#              #
#    Updated: 2019/09/05 19:36:05 by retounsi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Werror -Wextra

PATHFILE = ./libft

CC = gcc

FSANITISE_NAME = fsanitize

CC_FSANITISE = gcc -fsanitize=address -g

SRC_NAME = get_next_line.c ft_erase_column.c\
			ft_readtetris_check.c ft_which_square.c\
			ft_fill_square.c main.c

OBJ_NAME = $(SRC_NAME:.c=.o)

LIB = $(PATHFILE)/libft.a

all: $(NAME)

$(FSANITISE_NAME): $(LIB)
	$(CC_FSANITISE) -o $(FSANITISE_NAME) $(SRC_NAME) libft/libft.a

$(LIB):
	make -C $(PATHFILE)

$(NAME): $(LIB) $(OBJ_NAME) libft/libft.a
	$(CC) $(CFLAGS) -c $(SRC_NAME)
	$(CC) -o $(NAME) $(OBJ_NAME) libft/libft.a

clean:
	rm -f $(OBJ_NAME)
	make clean -C $(PATHFILE)

fclean:
	rm -f $(OBJ_NAME)
	rm -f $(NAME)
	make fclean -C $(PATHFILE)

re: fclean all
