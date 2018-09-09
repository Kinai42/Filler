/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 03:22:59 by dbauduin          #+#    #+#             */
/*   Updated: 2018/09/09 02:42:02 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_check(t_map *map)
{
	int	y;
	int	x;

	y = 2;
	while (++y < map->size_y - 3)
	{
		x = 2;
		while (++x < map->size_x - 3)
		{
			if (ft_strrchr(map->me, map->map[y][x]))
				if (ft_strrchr(map->adv, map->map[y][x + 3])
						|| ft_strrchr(map->adv, map->map[y][x - 3])
						|| ft_strrchr(map->adv, map->map[y + 3][x])
						|| ft_strrchr(map->adv, map->map[y - 3][x]))
					return (1);
		}
	}
	return (0);
}

int				ft_push_up(t_map *map, t_piece *p)
{
	int y;
	int x;

	y = map->size_y;
	while (--y >= 0)
	{
		x = map->size_x;
		while (--x >= 0)
			if (!ft_place(y, x, map, p))
			{
				ft_print(y, x, map);
				return (0);
			}
	}
	return (1);
}

int				ft_push_down(t_map *map, t_piece *p)
{
	int y;
	int x;

	y = -1;
	while (++y < map->size_y - 1)
	{
		x = -1;
		while (++x < map->size_x - 1)
			if (!ft_place(y, x, map, p))
			{
				ft_print(y, x, map);
				return (0);
			}
	}
	return (1);
}

static int		ft_count(t_map *map, t_piece *p, int y, int x)
{
	int	py;
	int	px;
	int o;
	int ret;

	py = -1;
	ret = 0;
	while (++py < p->size_y && (px = -1))
	{
		while (++px < p->size_x)
			if (p->piece[py][px] == '*' && !(o = 0))
			{
				while (++o < 4)
					if ((px + x + o) < map->size_x && (px + x - o) > 0 &&
							(py + y + o) < map->size_y && (py + y - o) > 0)
						if (ft_strrchr(map->adv, map->map[py + y]
									[px + x + o]) || ft_strrchr(map->adv,
										map->map[py + y][px + x - o]) ||
								ft_strrchr(map->adv, map->map[py + y + o]
									[px + x]) || ft_strrchr(map->adv,
										map->map[py + y - o][px + x]))
							ret += (4 - o);
			}
	}
	return (ret);
}

int				ft_algo_big(t_map *map, t_piece *p)
{
	int	y;
	int	x;
	int	touch;
	int tmp;

	touch = -1;
	y = map->size_y - (p->size_y - p->end_y);
	while (--y >= 0)
	{
		x = map->size_x - (p->size_x - p->end_x);
		while (--x >= 0)
			if (!ft_place(y, x, map, p))
			{
				if ((tmp = ft_count(map, p, y, x)) > touch)
				{
					touch = tmp;
					p->final_y = y;
					p->final_x = x;
				}
			}
	}
	if (touch == -1)
		return (1);
	ft_print(p->final_y, p->final_x, map);
	return (0);
}
