/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:25:36 by edhommee          #+#    #+#             */
/*   Updated: 2017/06/26 12:25:37 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char	*dst;
	char	*tmp;

	if (!(dst = (char*)ft_memalloc(sizeof(char) * n + 1)))
		return (NULL);
	tmp = dst;
	while (*s1 && n-- > 0)
	{
		*tmp++ = *s1++;
	}
	*tmp = '\0';
	return (dst);
}
