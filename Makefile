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

#-------------------- Define Color-------------------#
ifneq (,$(findstring xterm,${TERM}))
	R            := $(shell tput -Txterm setaf 1)
	G            := $(shell tput -Txterm setaf 2)
	Y            := $(shell tput -Txterm setaf 3)
	LP           := $(shell tput -Txterm setaf 4)
	P            := $(shell tput -Txterm setaf 5)
	B            := $(shell tput -Txterm setaf 6)
	W            := $(shell tput -Txterm setaf 7)
	RS := $(shell tput -Txterm sgr0)
else
	R            := ""
	G            := ""
	Y            := ""
	LP           := ""
	P            := ""
	B            := ""
	W            := ""
	RS           := ""
endif
#----------------------------------------------------#

NAME = ft_containers

MY_VEC = 	./tests/vector_tests/vector_test.cpp
ORG_VEC = 	./tests/vector_tests/Original.cpp

MY_TREE = 	./tests/map_tests/tree_test.cpp
#MY_MAP = 	./tests/map_tests/map_test.cpp.cpp
#ORG_MAP = 	./tests/map_tests/Original.cpp


FLAGS = -Wall -Wextra -Werror -std=c++98

################################## [sanitizer]  ##################################

# -fsanitize=address for address sanitizer
# -fsanitize=leak for leak sanitizer
# -fsanitize=undefined for undefined behavior sanitizer
# -fsanitize=thread for thread sanitizer
#SFLAGS = -fsanitize=address -fsanitize=undefined -fsanitize=leak -fsanitize=thread

####################################################################################
CC = c++ -g3

#------------------------------------------------------------------------------------------------------
all: $(NAME) $(OBJ) clean
$(NAME): $(OBJ)
# Compile MY_VEC and ORG_VEC files
	@$(CC) $(FLAGS) $(MY_VEC) -o MY_VEC
	@$(CC) $(ORG_VEC) -o ORG_VEC

# Compile MY_TREE files
	#$(CC) $(FLAGS) $(MY_TREE) -o MY_TREE


# Move MY_VEC and ORG_VEC to tests folder
	@mv MY_VEC ORG_VEC ./tests/vector_tests

# Move MY_TREE to tests folder
	@#mv MY_TREE ./tests/map_tests

	@echo "\033c"
	@echo "$(R)≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡ $(RS)"
	@echo "$(R)║$(LP)░░░░████████░░████████░░░█████░░░███░█████████░█████████░░█████░░░███░░████████░████████░░░░░████████░░░$(R)║$(RS)"
	@echo "$(R)║$(LP)░░░███░░░░░░░███░░░░███░███░███░░███░░░░███░░░░░░░███░░░░███░███░░███░███░░░░░░░███░░░░██░░░███░░░░░░░░░$(R)║$(RS)"
	@echo "$(R)║$(LP)░░░███░░░░░░░███░░░░███░███░░███░███░░░░███░░░░░░░███░░░░███░░███░███░█████████░████████░░░░█████████░░░$(R)║$(RS)"
	@echo "$(R)║$(LP)░░░███░░░░░░░███░░░░███░███░░░██████░░░░███░░░░░░░███░░░░███░░░██████░███░░░░░░░███░░░░██░░░░░░░░░███░░░$(R)║$(RS)"
	@echo "$(R)║$(LP)░░░░████████░░████████░░███░░░░████░░░░░███░░░░█████████░███░░░░████░░░████████░███░░░░░██░░████████░░░░$(R)║$(RS)"
	@echo "$(R)≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡ $(RS)"
	@echo "$                                   $(LP)            Created_By\n $(RS)"

	@echo "                                    $(Y)          █▀▀ █▀█ █▄▄   $(RS)"
	@echo "                                    $(Y)          █▄█ █▀█ █▄█   $(RS)"
	@echo "$                                    $(LP)  _____________________________$(RS)"
	@echo "\n"

test:
# Compare MY_VEC and ORG_VEC outputs
	@python3 Test_res_cmp.py

#------------------------------------------------------------------------------------------------------
leaks:
	@echo
	make re && make clean \
	&& valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-limit=no ./$(NAME)
	@echo "$(Y)——————————————————————————————————————————————————————————————————————————————————$(RS)"

#------------------------------------------------------------------------------------------------------
clean:
	@rm -rf $(OBJ)
	@echo "$(G)【OK】 $(RS)        $(R)❮ft_containers❯ objects have been cleaned$(RS)"
	@echo "$(Y)——————————————————————————————————————————————————————————————————————————————————$(RS)"

#------------------------------------------------------------------------------------------------------
fclean: clean
	@rm -rf ./tests/vector_tests/MY_VEC ./tests/vector_tests/ORG_VEC
	@#rm -rf ./tests/map_tests/MY_TREE
	@echo "\033c"
	@echo "$(G)【OK】 $(RS)        $(R)❮ft_containers executable❯ DELETED$(RS)"

	@echo "$(Y)——————————————————————————————————————————————————————————————————————————————————$(RS)"
#------------------------------------------------------------------------------------------------------
re: fclean all
#------------------------------------------------------------------------------------------------------
.PHONY: all clean fclean re
#------------------------------------------------------------------------------------------------------