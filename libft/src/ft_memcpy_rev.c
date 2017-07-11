/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:26:26 by edhommee          #+#    #+#             */
/*   Updated: 2017/05/20 17:21:32 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy_rev(void *dst, const void *src, size_t len)
{
	char	*temp1;
	char	*temp2;

	if (!len || dst == src)
		return (dst);
	temp1 = (char *)dst;
	temp2 = (char *)src;
	while (len--)
		temp1[len] = temp2[len];
	return (dst);
}
