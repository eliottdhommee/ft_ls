/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:37:58 by edhommee          #+#    #+#             */
/*   Updated: 2017/05/20 17:28:09 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	max;

	if (*little == '\0')
		return ((char *)big);
	max = ft_strlen(little);
	while ((*big != '\0') && (max <= len))
	{
		if ((*big == *little) && (ft_memcmp(big, little, max) == 0))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
