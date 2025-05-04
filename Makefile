NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = mlx
LIBFT_DIR = libft

INCLUDES = -I$(MLX_DIR) -I$(LIBFT_DIR)
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = 	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		main.c\
		utils/utils_error.c\
		init/init_game_struct.c\
		parsing/parse.c\
		parsing/check_texture.c\
		parsing/check_color.c\
		parsing/check_map.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(MLX_DIR) -lmlx $(LIBFT) $(INCLUDES) -framework OpenGL -framework AppKit -framework Foundation

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
