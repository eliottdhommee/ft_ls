/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolkit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 03:23:50 by edhommee          #+#    #+#             */
/*   Updated: 2017/05/21 03:29:13 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		isconv(char c)
{
	if (c == '%')
		return (1);
	return (0);
}

int		istype(char c)
{
	if (ft_strchr("diouxXDOUeEfFgGaAcCsSpn", c))
		return (1);
	return (0);
}

int		isflag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == 39)
		return (1);
	return (0);
}

int		islenght(char c)
{
	if (ft_strchr("hljtzql", c))
		return (1);
	return (0);
}
