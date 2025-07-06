#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_data
{
    int		fd;
    int		cnt;
    char	**entire_fd;
    char	*trimmed;
    char	*texture[4];
	
    int		check_floor_color;
	int		check_ceiling_color;
    int		floor_color;
    int		ceiling_color;
	int		comma_cnt;
	char	**rgb;
	char	**cleaned;
    int		r;
	int		g;
	int		b;

    int		cnt_map_lines;
    char	**map;
    char	**map_copy;

}   t_data;

/*_____ERRORS_____*/
void	ft_error(char *str);
void	free_entire_fd(t_data *game);
void	free_error_fd(char *str, t_data *game);
void	free_map(t_data *game);
void	free_error_map(char *str, t_data *game);
void	free_map_copy(t_data *game);
void	free_err_all_maps(char *str, t_data *game);

/*_____INIT_____*/
void	init_struct(t_data *game);

/*_____PARSING_____*/
void	parse(t_data *game, char *file);
//TEXTURES
int		check_texture(t_data *game, char *line);
void	check_textures_path(char *path);
//COLORS
void		check_color(t_data *game, char *line);
void		extract_rgb_values(t_data *game, char *str, int i);
void		validate_rgb_components(t_data *game, int i, int j);
void		free_str_array(char **arr);
void		free_str_array_error(t_data *game);
int 		create_trgb(int t, t_data *game);
//MAP
void	parse_map(t_data *game, int 	map_start_index);
int		flood_fill(t_data *game, int y, int x);
void	map_borders(t_data *game);
void	check_invalid_zero(t_data *game);

/*_____MAP_____*/
void	map_is_valid(t_data *game);

#endif