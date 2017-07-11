/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:19:46 by edhommee          #+#    #+#             */
/*   Updated: 2017/05/20 17:20:54 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*chk;
	unsigned char	mark;
	int				i;

	i = 0;
	mark = (unsigned char)c;
	chk = (unsigned char *)s;
	while (n > 0)
	{
		if (chk[i] == mark)
			return (chk + i);
		i++;
		n--;
	}
	return (NULL);
}
