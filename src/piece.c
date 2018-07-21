#include "filler.h"
#define UL unsigned long
static void		ft_piece_size(t_piece *p)
{
	int		y;
	int		x;

	y = -1;
	p->start_x = p->size_x;
	p->start_y = p->size_y;
	while (++y < p->size_y)
	{
		x = -1;
		while (++x < p->size_x)
			if (p->piece[y][x] == '*')
			{
				if (x < p->start_x)
					p->start_x = x;
				if (x > p->end_x)
					p->end_x = x;
				if (y < p->start_y)
					p->start_y = y;
				if (y > p->end_y)
					p->end_y = y;
			}
	}
	p->real_size_x = (p->end_x - p->start_x) + 1;
	p->real_size_y = (p->end_y - p->start_y) + 1;
}

static void		ft_get_piece(t_piece *p)
{
	int		i;
	char	*line;

	i = -1;
    //printf("aaaa\n");
	//if (p->piece != NULL)
	//	free(p->piece);
    //printf("IF p->piece == NULL\n");
	if(!(p->piece = (char **)malloc(sizeof(char *) * (UL)(p->size_y))))
        exit (-1);
    //printf("P->size\n");
    i = -1;
	while (++i < p->size_y)
	{
    //printf("WHILE\n\n");
		if ((line = ft_gnl(0)))
        {
            //printf("While if\n\n");
		    p->piece[i] = ft_strdup(line);
	        free(line);
        }
    }
	ft_piece_size(p);
}

void		init_piece(char *str, t_piece *p)
{
	int		i;
	int		num;

	i = -1;
	p->size_x = 0;
	p->size_y = 0;
	while (str[++i])
	{
		num = 0;
        while ((str[i] >= '0') && (str[i] <= '9'))
		    num = (num * 10) + (str[i++] - '0');
		if (p->size_y == 0)
			p->size_y = num;
		else if (p->size_x == 0)
			p->size_x = num;
	}
    //printf("PIECE %d - %d\n", p->size_y, p->size_x);
    ft_get_piece(p);
}
