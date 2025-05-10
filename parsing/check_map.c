#include "../cub3D.h"

static int  map_is_rectangular(t_data *game)
{
    
}

static int  map_is_closed(t_data *game)
{

}

void    map_is_valid(t_data *game)
{
    if (map_is_rectangular(game));
        ft_error("ERROR: Map is not rectangular!\n");//ft_free_error et pas ft_error.
    else if (map_is_closed(game))
        ft_error("ERROR: Map is not closed!\n");
}
