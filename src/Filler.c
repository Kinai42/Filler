#include "filler.h"

static void		ft_read(t_map *map, t_piece *p)
{
	char		*line;

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

    line = ft_gnl(0);
    if (map->player == 0)
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
    }
    //printf("%d me [%s] adv [%s]\n", map->player, map->me, map->adv);
    free(line);
}

static void		ft_init(t_map *map, t_piece *piece)
{
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
	piece->contact = 0;
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
 	while (1)
	{
		ft_read(map, piece);
        //printf("%d %d - %d %d\n", map->size_y, map->size_x, piece->size_y, piece->size_x);
        //printf("%s\n", &piece->piece[2]);
        if (ft_run(map, piece))
		{
			if (ft_last(map, piece))
			{
				ft_print(piece, map);
				return (0);
			}
		}
	}
}

void	ft_print(t_piece *p, t_map *map)
{
	ft_putnbr(p->final_y);
	ft_putchar(' ');
	ft_putnbr(p->final_x);
	ft_putchar('\n');
	map->pos_me_x = p->final_x;
	map->pos_me_y = p->final_y;
}
