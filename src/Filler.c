#include "filler.h"

static void		ft_read(t_map *map, t_piece *p)
{
	char		*line;

    //p->piece = NULL;
	while ((line = ft_gnl(0)))
	{
		if (!ft_strncmp(line, "Plateau", 6))
			init_map(line, map);
		if (!ft_strncmp(line, "Piece", 4))
        {
            init_piece(line, p);
            free (line);
            return ;
        }
        free(line);
	}
}

static void		ft_player(t_map *map)
{
    char		*line;

    if ((line = ft_gnl(0)))
    {
        if (ft_strstr(line, "p1"))
        {
            map->player = 1;
		    map->adv = ft_strdup("Xx");
		    map->me = ft_strdup("Oo");
        }
        else if (ft_strstr(line, "p2"))
        {
            map->player = 2;
		    map->adv = ft_strdup("Oo");
		    map->me = ft_strdup("Xx");
        }
        free(line);
    }
    if (map->player == 0 && (write(1, "error\n", 6)))
        exit (0);
}

static void		ft_init(t_map *map, t_piece *piece)
{
    //map->map = NULL;
	map->player = 0;
	map->size_x = 0;
	map->size_y = 0;
	map->pos_adv_x = 0;
	map->pos_adv_y = 0;
	map->pos_me_x = 0;
	map->pos_me_y = 0;
    piece->final_x = 0;
	piece->final_y = 0;
	piece->size_x = 0;
	piece->size_y = 0;
    piece->start_x = 0;
	piece->start_y = 0;
	piece->end_x = 0;
	piece->end_y = 0;
}

int main()
{
    t_map	*map;
	t_piece	*piece;
    

    if (!(map = (t_map *)malloc(sizeof(t_map))) ||
	(!(piece = (t_piece *)malloc(sizeof(t_piece)))))
        return (0);
    ft_init(map, piece);
    ft_player(map);
    //printf("%s-%s\n", map->adv, map->me);
    //if (ft_strrchr(map->me, 'o'))
    //printf("%s,\n", ft_strrchr(map->me, 'o'));
 	while (1)
	{
		ft_read(map, piece);
        //printf("%d %d - %d %d\n", map->size_y, map->size_x, piece->size_y, piece->size_x);
        //printf("%s\n", &piece->piece[2]);
        if (ft_run(map, piece))
		{
			if (ft_last(map, piece))
			{
				ft_print(piece->final_y, piece->final_x, map);
				return (0);
			}
		}
        free_map_piece(map, piece);
        //ft_parrfree(map->map);
        //ft_parrfree(piece->piece);
	}
}

void	ft_print(int y, int x, t_map *map)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
	map->pos_me_y = y;
	map->pos_me_x = x;
}
