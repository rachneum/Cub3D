#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
#include <fcntl.h>

typedef struct s_data
{
	char	**map;
	char	*texture[4];
	int		check_floor_color;
	int		check_ceiling_color;
	int		nb_map_lines;
	char	**map_copy;


}	t_data;

/*________UTILS________*/
void	ft_error(char *str);
void	ft_free_error(char *str, t_data *game);
int 	check_north(t_data *game, char *line);
int 	check_south(t_data *game, char *line);
int 	check_west(t_data *game, char *line);
int		check_east(t_data *game, char *line);
char	**copy_map(char **src_map);
void	ft_free_all_error(char *str, t_data *game);

/*________INIT________*/
void    init_game_struct(t_data *game);

/*________PARSE________*/
void    parse(t_data *game, char *file);
int		check_texture(t_data *game, char *line);
int		check_textures_path(char *path);
void	check_texture_exist(t_data *game);
void	textures_own_path(t_data *game);
int		check_color(t_data *game, char *line);
int		parse_map(t_data *game, char **lines);
int		maps_content(char *line);

/*________CHECK_MAP________*/
void    map_is_valid(t_data *game);

#endif