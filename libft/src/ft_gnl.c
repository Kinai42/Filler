/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 03:25:25 by dbauduin          #+#    #+#             */
/*   Updated: 2018/08/09 03:25:30 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
