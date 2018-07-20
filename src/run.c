#include "filler.h"

static int	ft_big_map(t_map *map, t_piece *p)
{
	if (ft_check(map))
	{
    p->final_x = 0;
    p->final_y = 0;
		if (map->pos_me_y < map->pos_adv_y)
			if (ft_push_UP(map, p))
				return (1);
		else if (map->pos_me_y >= map->pos_adv_y)
			if (ft_push_DOWN(map, p))
				return (1);
	}
	else
		if(ft_algo_big(map, p))
			return (1);
	return (0);
}

static int	ft_small_map(t_map *map, t_piece *p)
{
    int ret;

    ret = 0;
    p->final_x = 0;
    p->final_y = 0;
	if (map->pos_me_y < (map->size_y / 2))
	{
        //printf("1111111111111\n");
		if (map->pos_me_x < (map->size_x / 2))
			ret = ft_algo_UL(map, p);
		else
			ret = ft_algo_UR(map, p);
	}
	else if (map->pos_me_y >= (map->size_y / 2))
	{
        //printf("222222222222\n");
		if (map->pos_me_x < (map->size_x / 2))
			ret = ft_algo_DL(map, p);
		else
			ret = ft_algo_DR(map, p);
	}
	return (ret);
}

int	ft_run(t_map *map, t_piece *p)
{
	if (map->size_y < 20)
    {
		//printf("SMALL\n");
        return (ft_small_map(map, p));

    }
	if (map->size_y >= 20)
    {
		//printf("BIG\n");
		return (ft_big_map(map, p));
    }
	return (0);
}


int		ft_place(int y, int x, t_map *map, t_piece *p)
{
	int py;
	int px;
	int count;

	py = -1;
	count = 0;
	if (y + p->size_y > map->size_y || x + p->size_x > map->size_x)
		return (1);
	while (++py <= (p->size_y - 1))
	{
	px = -1;
		while (++px <= (p->size_x - 1))
		{
			if (p->piece[py][px] == '*' && ft_strrchr(map->adv, map->map[y + py][x + px]))
				return (1);
			if (p->piece[py][px] == '*' && ft_strrchr(map->me, map->map[y + py][x + px]))
				count++;
		}
	}
	if (count == 1)
	{
		p->final_x = x;
		p->final_y = y;
		return (0);
	}
	return (1);
}

int		ft_last(t_map *map, t_piece *p)
{
	int	y;
	int	x;

	y = -1;
	p->final_x = 0;
	p->final_y = 0;
	while (++y < map->size_y - 1)
	{
		x = -1;
		while (++x < map->size_x - 1)
			if (!ft_place(y, x, map, p))
			{
				ft_print(p, map);
				return (0);
			}
	}
	return (1);
}
