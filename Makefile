# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfinni <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 16:08:05 by tfinni            #+#    #+#              #
#    Updated: 2023/05/09 16:14:34 by tfinni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= client
NAME2	= server
SRC1	= client.c
SRC2	= server.c make_list.c
OBJ1	= $(SRC1:.c=.o)
OBJ2	= $(SRC2:.c=.o)
CC		= cc
FLAGS	= -Wall -Wextra -Werror
INCLUDE	= -I include
LIBFT	= libft/libft.a

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1)
	make -C libft
	$(CC) $(FLAGS) $(OBJ1) $(INCLUDE) $(LIBFT) -o $(NAME1)

$(NAME2): $(OBJ2)
	$(CC) $(FLAGS) $(OBJ2) $(INCLUDE) $(LIBFT) -o $(NAME2)

clean:
	rm -f $(OBJ1) $(OBJ2)
	make clean -C libft

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)
	make fclean -C libft

re: fclean all
