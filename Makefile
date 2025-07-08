NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

LIBFT = ./libft/libft.a
INCLUDES = -I./libft

SRCS = get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	errors/error.c \
	errors/error_2.c \
	main.c \
	init_struct.c \
	parsing/parse/parse.c \
	parsing/parse/parse_2.c \
	parsing/textures/textures.c \
	parsing/textures/textures_2.c \
	parsing/colors/colors.c \
	parsing/colors/colors_2.c \
	parsing/map/map.c \
	parsing/map/map_2.c \
	parsing/map/map_3.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)


$(LIBFT):
	make -C ./libft


clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all
