#include "libft.h"

char    ft_strdchr(char *src, char *to_find)
{
    int i;

    i = -1;
    while (src[++i])
            if (!ft_strrchr(to_find, src[i]))
                return (1);
    return (0);
}
