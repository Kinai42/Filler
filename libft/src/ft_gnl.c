#include "libft.h"

#include <stdlib.h>
#include <unistd.h>

char	*ft_gnl(int fd)
{
	char	*line;
	char	c;

	line = ft_strnew(1);
	while (read(fd, &c, 1) == 1 && c != '\n')
		if (!ft_strpush(&line, c))
            return (0);
	if (c == '\n')
		return (line);
	free(line);
	return ((char*)0);
}
