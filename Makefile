OBJ = $(addsuffix .o, $(addprefix obj/, Filler big_map map piece run small_map))
OBJ_W ?= $(shell find $(P_OBJ) | grep \\.o$)

NAME = dbauduin.filler

all: obj $(NAME)

obj:
	mkdir obj

$(NAME): $(OBJ)
	@make -C libft
	@gcc -o $(NAME) $(OBJ) libft/libft.a

obj/%.o: src/%.c
	@gcc -o $@ -c $< -I include/ -I libft/include -Weverything

clean:
	@rm -f $(OBJ_W)

fclean: clean
	@rm -f $(NAME)

re: fclean all
