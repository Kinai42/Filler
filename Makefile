OBJ = $(addsuffix .o, $(addprefix obj/, Filler big_map map piece run small_map))
OBJ_W ?= $(shell find obj | grep \\.o$)

NAME = dbauduin.filler
cc =	-O1 -g -fsanitize=address	\
		-fno-omit-frame-pointer		\
		-fsanitize-address-use-after-scope


all: obj $(NAME)

obj:
	mkdir obj

$(NAME): $(OBJ)
	@make -C libft
	@gcc -Wall -Werror -Wextra -o $(NAME) $(OBJ) libft/libft.a

obj/%.o: src/%.c
	@gcc -o $@ -c $< -I include/ -I libft/include

clean:
	@rm -f $(OBJ_W)
	@make -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
