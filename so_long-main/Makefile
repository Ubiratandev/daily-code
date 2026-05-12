##verify how to compile mlx.h

NAME = so_long


CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX = libmlx.a -lX11 -lXext -lm 

OBJS = so_long.o utils.o

all: $(NAME)

$(NAME): so_long.o utils.o
	$(CC) $(CFLAGS) so_long.o utils.o $(MLX) -o $(NAME)

so_long.o: so_long.c so_long.h
	$(CC) $(CFLAGS) -c so_long.c -o so_long.o

utils.o: utils.c so_long.h
	$(CC) $(CFLAGS) -c utils.c -o utils.o

clean:
	@rm -f so_long.o utils.o

fclean: clean
	@rm -f $(NAME)
	@echo "🚮 Executável removido!"

# Recompilar do zero
re: fclean all

.PHONY: all clean fclean re

