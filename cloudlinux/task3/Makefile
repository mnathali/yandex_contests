NAME = cmd_set

SRC = combo_cmd.c memory_functions.c str_functions.c

HEADER = combo_cmd.h

OBJ = $(patsubst %.c, %.o, $(SRC))

COMPILER = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ): $(HEADER)

%.o: %.c
	$(COMPILER) $(FLAGS) -c $<

$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS) $(OBJ) -o $@

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all
