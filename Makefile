CC=cc
CFLAGS=-Wall -Wextra -Werror -g -fsanitize=address -fno-omit-frame-pointer -I mlx
SOURCEFILES=src/main.c src/mapcreate.c src/mapchecker.c src/textures.c src/display.c src/move.c src/utils.c
OBJECTS=$(patsubst src/%.c,objects/%.o,$(SOURCEFILES))
OBJDIR=objects
NAME=so_long

all: $(OBJECTS) $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C mlx/
	$(MAKE) -C libft/
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -L. -lft -Lmlx -lmlx -lz -lXext -lX11

$(OBJDIR)/%.o: src/%.c
	@mkdir -p objects
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJECTS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
