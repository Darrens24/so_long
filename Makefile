CC = gcc

NAME = a.out

OBJ = errors.c \
		get_next_line.c \
		images.c \
		images2.c \
		get_next_line_utils.c \
		map.c \
		graphics.c \
		map_elements.c \
		map_elements_2.c \
		hooks.c \
		main.c \

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a libftprintf.a

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all