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
	int		floor_color;
	int		ceiling_color;
}	t_data;

/*________UTILS_ERROR________*/
void	ft_error(char *str);

/*________INIT________*/
void    init_game_struct(t_data *game);

/*________PARSE________*/
void    parse(t_data *game, char *file);
int		check_texture(t_data *game, char *line);
int		check_color(t_data *game, char *line);
int		parse_map(t_data *game, char **lines);

#endif