/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:37:35 by edhommee          #+#    #+#             */
/*   Updated: 2017/05/20 17:27:59 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	char			*book;
	unsigned int	i;

	i = 0;
	book = malloc(size + 1 * sizeof(char));
	if (book == NULL)
		return (0);
	while (i <= size)
	{
		book[i] = '\0';
		i++;
	}
	return (book);
}
