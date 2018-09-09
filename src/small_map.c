/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 03:23:24 by dbauduin          #+#    #+#             */
/*   Updated: 2018/09/09 02:49:06 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_algo_ul(t_map *map, t_piece *p)
{
	int	y;
	int	x;

	y = map->size_y + 1;
	p->final_x = 0;
	p->final_y = 0;
	while (--y > 0)
	{
		x = map->size_x + 1;
		while (--x > 0)
			if (!ft_place(y, x, map, p))
			{
				ft_print(y, x, map);
				return (0);
			}
	}
	return (1);
}

int		ft_algo_ur(t_map *map, t_piece *p)
{
	int	y;
	int	x;

	y = map->size_y + 1;
	p->final_x = 0;
	p->final_y = 0;
	while (--y > 0)
	{
		x = -1;
		while (++x < map->size_x)
			if (!ft_place(y, x, map, p))
			{
				ft_print(y, x, map);
				return (0);
			}
	}
	return (1);
}

int		ft_algo_dl(t_map *map, t_piece *p)
{
	int	y;
	int	x;

	y = -1;
	p->final_x = 0;
	p->final_y = 0;
	while (++y < map->size_y)
	{
		x = map->size_x;
		while (--x > 0)
			if (!ft_place(y, x, map, p))
			{
				ft_print(y, x, map);
				return (0);
			}
	}
	return (1);
}

int		ft_algo_dr(t_map *map, t_piece *p)
{
	int	y;
	int	x;

	y = -1;
	p->final_x = 0;
	p->final_y = 0;
	while (++y < map->size_y)
	{
		x = -1;
		while (++x < map->size_x)
			if (!ft_place(y, x, map, p))
			{
				ft_print(y, x, map);
				return (0);
			}
	}
	return (1);
}
