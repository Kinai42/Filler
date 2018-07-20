/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:27:16 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/21 16:27:19 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(long long n)
{
	char				*s;
	int					i;
	long long			k;

	k = n;
    i = ft_intlen(n);
    i += n < 0 ? 1 : 0;
	s = ft_strnew(i);
	if (s == NULL)
		return (NULL);
	if (k < 0)
	{
		s[0] = '-';
		k *= -1;
	}
	else if (k == 0)
		s[0] = '0';
    i--;
	while (k > 0)
	{
		s[i] = (k % 10) + 48;
		k /= 10;
		i--;
	}
	return (s);
}
