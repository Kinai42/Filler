/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 03:23:39 by dbauduin          #+#    #+#             */
/*   Updated: 2018/08/09 03:24:23 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

# define UL unsigned long

typedef struct		s_map
{
	int				player;

	char			**map;
    char             *me;
    char             *adv;

	int				size_x;
	int				size_y;

	int				pos_adv_x;
	int				pos_adv_y;
	int				pos_me_x;
	int				pos_me_y;

	int				first_x;
	int				first_y;

}					t_map;

typedef struct		s_piece
{
	char			**piece;

	int				contact;
	int				final_x;
	int				final_y;


	int				size_x;
	int				size_y;

	int				real_size_x;
	int				real_size_y;

	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;

}					t_piece;


void    init_map(char *line, t_map *map);
void    init_piece(char *line, t_piece *p);
int     ft_run(t_map *map, t_piece *p);
int     ft_check(t_map *map);


int     ft_algo_UL(t_map *map, t_piece *p);
int     ft_algo_UR(t_map *map, t_piece *p);
int     ft_algo_DL(t_map *map, t_piece *p);
int     ft_algo_DR(t_map *map, t_piece *p);

int     ft_push_UP(t_map *map, t_piece *p);
int     ft_push_DOWN(t_map *map, t_piece *p);
int     ft_algo_big(t_map *map, t_piece *p);

int     ft_place(int y, int x, t_map *map, t_piece *p);

void    ft_position(t_map *map);
int     ft_last(t_map *map, t_piece *p);
void    ft_print(int y, int x, t_map *map);

void    free_map_piece(t_map *map, t_piece *piece);




#endif
