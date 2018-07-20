#include "filler.h"

void			ft_position(t_map *map)
{
    int			x;
    static int	y;

    if (y == map->size_y)
        return ;
    y = 0;
    while (++y < (map->size_y))
    {
        x = 0;
        while (++x < (map->size_x))
        {
            if (ft_strrchr(map->me, map->map[y][x]))
            {
                map->pos_me_x = x;
                map->pos_me_y = y;
            }
            else if (ft_strrchr(map->adv, map->map[y][x]))
            {
                map->pos_adv_x = x;
                map->pos_adv_y = y;
            }
        }
    }
    //printf("ME = [%d] [%d]\n", map->pos_me_y, map->pos_me_x);
    //printf("ADV = [%d] [%d]\n", map->pos_adv_y, map->pos_adv_x);
}

static void			ft_get_map(t_map *map)
{
    unsigned int			i;
    char		*line;

    line = ft_gnl(0);
    free(line);
    if(!(map->map = (char **)malloc(sizeof(char *) * (map->size_y))))
        exit (-1);
    i = 0;
    while (i <= (map->size_y - 1))
    {
        if ((line = ft_gnl(0)))
        {
            map->map[i] = ft_strdup(&line[4]);
            free(line);
        }
        i++;
    }
}

void			init_map(char *str, t_map *map)
{
    int			i;
    int			num;

    i = 6;
    while (str[i])
    {
        num = 0;
        while ((str[i] >= '0') && (str[i] <= '9'))
            num = (num * 10) + (str[i++] - '0');
        if (map->size_y == 0)
            map->size_y = num;
        else if (map->size_x == 0)
            map->size_x = num;
        i++;
    }
    ft_get_map(map);
    ft_position(map);
}
