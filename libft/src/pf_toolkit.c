/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolkit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:41:14 by mgalliou          #+#    #+#             */
/*   Updated: 2017/06/16 15:58:25 by mgalliou         ###   ########.fr       */
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
