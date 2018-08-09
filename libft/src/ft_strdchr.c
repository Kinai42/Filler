/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 03:26:14 by dbauduin          #+#    #+#             */
/*   Updated: 2018/08/09 03:26:21 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
