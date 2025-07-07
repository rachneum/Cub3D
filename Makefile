#NAME = cub3D
#CC = cc
#CFLAGS = -Wall -Wextra -Werror -fsanitize=address
#
#LIBFT = ./libft/libft.a
#LIBMLX = ./mlx/libmlx.a
#INCLUDES = -I./libft -I./minilibx-linux
#
#SRCS = get_next_line/get_next_line.c \
#	get_next_line/get_next_line_utils.c \
#	errors/error.c \
#	errors/error_2.c \
#	main.c \
#	init_struct.c \
#	parsing/parse.c \
#	parsing/textures/textures.c \
#	parsing/textures/textures_2.c \
#	parsing/colors/colors.c \
#	parsing/colors/colors_2.c \
#	parsing/map/map.c \
#	parsing/map/map_2.c \
#	parsing/map/map_3.c
#
#OBJS = $(SRCS:.c=.o)
#
#all: $(NAME)
#
#$(NAME): $(LIBFT) $(LIBMLX) $(OBJS)
#	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) -Lmlx -lmlx -lX11 -lXext -lm
#
#
#$(LIBFT):
#	make -C ./libft
#
#$(LIBMLX):
#	make -C minilibx-linux
#
#clean:
#	make clean -C ./libft
#	rm -f $(OBJS)
#
#fclean: clean
#	make fclean -C ./libft
#	rm -f $(NAME)
#
#re: fclean all
#

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

MLX_DIR = mlx
LIBFT_DIR = libft

INCLUDES = -I$(MLX_DIR) -I$(LIBFT_DIR)
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = 	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c\
		errors/error.c\
		errors/error_2.c\
		main.c\
		init_struct.c\
		parsing/parse.c\
		parsing/textures/textures.c\
		parsing/textures/textures_2.c\
		parsing/colors/colors.c\
		parsing/colors/colors_2.c\
		parsing/map/map.c\
		parsing/map/map_2.c\
		parsing/map/map_3.c\

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
