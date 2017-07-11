/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:41:05 by mgalliou          #+#    #+#             */
/*   Updated: 2017/05/31 12:13:44 by mgalliou         ###   ########.fr       */
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
