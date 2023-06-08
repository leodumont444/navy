##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME_EXE = navy

SRC =	src/main.c \
		src/lib/lib.c \
		src/error_handling/error_handling.c \
		src/error_handling/open_file.c \
		src/error_handling/free_all.c \
		src/map/create_map.c \
		src/map/print_map.c \
		src/map/place_boats.c \
		src/game_loop/game_loop_ennemy.c \
		src/game_loop/game_loop_host.c \
		src/game_loop/win_condition.c \
		src/game_loop/attack.c \
		src/game_loop/defend.c \

SRC_TEST = $(SRC) /tests/test.c

OBJ	=	$(SRC:.c=.o)

CFLAGS = $(LIB_I_FLAGS) -Wall -Wextra

LIB_I_FLAGS = -I./include/ -L./lib/ -lmy

all: $(NAME_EXE)

clean:
	rm -f $(NAME_EXE)

fclean: clean
	rm -f $(OBJ)
	make -sC lib/printf fclean

$(NAME_EXE):	$(OBJ)
	make -C lib/printf/
	gcc $(OBJ) -o $(NAME_EXE) $(CFLAGS)

debug:
	gcc $(SRC) -g -o $(NAME_EXE) $(CFLAGS)

re: fclean all
