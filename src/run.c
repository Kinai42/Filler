/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 03:23:20 by dbauduin          #+#    #+#             */
/*   Updated: 2018/09/09 02:47:59 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_big_map(t_map *map, t_piece *p)
{
	if (!ft_check(map))
	{
		if (map->pos_me_y < map->pos_adv_y)
			return (ft_push_up(map, p));
		else
			return (ft_push_down(map, p));
	}
	else
	{
		if (ft_algo_big(map, p))
			return (1);
	}
	return (0);
}

static int	ft_small_map(t_map *map, t_piece *p)
{
	int ret;

	ret = 0;
	if (map->pos_me_y < (map->size_y / 2))
	{
		if (map->pos_me_x < (map->size_x / 2))
			ret = ft_algo_ul(map, p);
		else
			ret = ft_algo_ur(map, p);
	}
	else
	{
		if (map->pos_me_x < (map->size_x / 2))
			ret = ft_algo_dl(map, p);
		else
			ret = ft_algo_dr(map, p);
	}
	return (ret);
}

int			ft_run(t_map *map, t_piece *p)
{
	if (map->size_y < 20)
	{
		return (ft_small_map(map, p));
	}
	else if (map->size_y >= 20)
	{
		return (ft_big_map(map, p));
	}
	return (0);
}

int			ft_place(int y, int x, t_map *map, t_piece *p)
{
	int py;
	int px;
	int count;

	py = -1;
	count = 0;
	if (y + p->size_y > map->size_y || x + p->size_x > map->size_x)
		return (1);
	while (++py < p->size_y)
	{
		px = -1;
		while (++px < p->size_x)
		{
			if (p->piece[py][px] == '*' &&
					ft_strrchr(map->adv, map->map[y + py][x + px]))
				return (1);
			if (p->piece[py][px] == '*' &&
					ft_strrchr(map->me, map->map[y + py][x + px]))
				count++;
		}
	}
	if (count == 1)
		return (0);
	return (1);
}

int			ft_last(t_map *map, t_piece *p)
{
	int	y;
	int	x;

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
