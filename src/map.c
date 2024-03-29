/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 03:23:01 by dbauduin          #+#    #+#             */
/*   Updated: 2018/09/09 03:11:41 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}

static void		ft_get_map(t_map *map)
{
	int			i;
	char		*line;

	line = ft_gnl(0);
	free(line);
	if (!(map->map = (char **)malloc(sizeof(char *) * (map->size_y))))
		exit(-1);
	i = 0;
	while (i < map->size_y)
	{
		if ((line = ft_gnl(0)))
		{
			if (ft_strdchr(&line[4], ".xXoO") ||
					(int)ft_strlen(line) != (map->size_x + 4))
			{
				write(1, "ERROR MAP\n", 10);
				exit(0);
			}
			map->map[i++] = ft_strdup(&line[4]);
			free(line);
		}
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

void			free_map_piece(t_map *map, t_piece *piece)
{
	int i;

	i = map->size_y;
	while (--i >= 0)
		free(map->map[i]);
	free(map->map);
	i = piece->size_y;
	while (--i >= 0)
		free(piece->piece[i]);
	free(piece->piece);
}
