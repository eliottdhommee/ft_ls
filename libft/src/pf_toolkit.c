/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_toolkit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:24:32 by edhommee          #+#    #+#             */
/*   Updated: 2017/06/26 12:24:34 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	istype(int c)
{
	if (ft_strchr("diouxXDOUfFCcSspnbw%", c) && c)
		return (1);
	return (0);
}

int	isflag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+' || c == 39)
		return (1);
	return (0);
}

int	islenght(char c)
{
	if (ft_strchr("hljtzqL", c) && c)
		return (1);
	return (0);
}

int	ismidwchar(unsigned int c)
{
	if (c >= 0xFFFFFF80 && c <= 0xFFFFFFBF)
		return (1);
	return (0);
}

int	isbegwchar(unsigned int c)
{
	if (c >= 0xFFFFFFC0 && c <= 0xFFFFFFF7)
		return (1);
	return (0);
}
