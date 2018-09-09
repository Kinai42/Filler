# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 03:22:48 by dbauduin          #+#    #+#              #
#    Updated: 2018/09/09 03:21:10 by dbauduin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_DEF	?= 	\e[38;5;15m
OK		?=	\e[38;5;47m

OBJ = $(addsuffix .o, $(addprefix obj/, filler big_map map piece run small_map))
OBJ_W ?= $(shell find obj | grep \\.o$)

NAME = dbauduin.filler
cc =	-O1 -g -fsanitize=address	\
		-fno-omit-frame-pointer		\
		-fsanitize-address-use-after-scope


all: obj $(NAME)

obj:
	@mkdir obj

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(cc) -Wall -Werror -Wextra -o $(NAME) $(OBJ) libft/libft.a
	@printf "$(OK)[+][FILLER] Done$(C_DEF)\n"

obj/%.o: src/%.c
	@gcc $(cc)  -Wall -Wextra -Werror -o $@ -c $< -I include/ -I libft/include

clean:
	@rm -f $(OBJ_W)
	@make -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
