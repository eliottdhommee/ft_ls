/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:38:29 by edhommee          #+#    #+#             */
/*   Updated: 2017/05/20 17:28:18 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*mark;

	mark = (char *)s + ft_strlen(s);
	while (*mark != c)
	{
		if (mark == s)
		{
			return (NULL);
		}
		mark--;
	}
	return (mark);
}
