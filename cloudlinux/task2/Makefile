NAME = ls_dir

SRC = list_dir.c

OBJ = $(patsubst %.c, %.o, $(SRC))

COMPILER = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(COMPILER) $(FLAGS) -c $<

$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS) $(OBJ) -o $@

clean:
	@if [ -e $(OBJ) ]; then rm $(OBJ); fi

fclean: clean
	@if [ -e $(NAME) ]; then rm $(NAME); fi

re: fclean all
