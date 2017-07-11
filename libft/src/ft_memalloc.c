/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:18:51 by edhommee          #+#    #+#             */
/*   Updated: 2017/05/20 17:20:35 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memalloc(size_t size)
{
	size_t	*book;

	book = malloc(size * sizeof(size_t));
	if (book == NULL)
		return (NULL);
	ft_bzero(book, size);
	return (book);
}
