# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 03:46:21 by gabdoush          #+#    #+#              #
#    Updated: 2023/01/11 10:59:05 by gabdoush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

FILES = ./tests/vector_test.cpp\

OBJ = $(FILES:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++ -g3

all: $(NAME) $(OBJ) clean

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re