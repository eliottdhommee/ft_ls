/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_nbrtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:22:58 by edhommee          #+#    #+#             */
/*   Updated: 2017/06/26 12:23:00 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t		cast_signed_nbr(t_conv *conv)
{
	if (conv->len == hh)
		return ((char)conv->ptr);
	else if (conv->len == h)
		return ((short)conv->ptr);
	else if (conv->len == l)
		return ((long)conv->ptr);
	else if (conv->len == ll)
		return ((long long)conv->ptr);
	else if (conv->len == j)
		return ((intmax_t)conv->ptr);
	else if (conv->len == z)
		return ((ssize_t)conv->ptr);
	else
		return ((int)conv->ptr);
}

static uintmax_t	cast_unsigned_nbr(t_conv *conv)
{
	if (conv->len == hh)
		return ((unsigned char)conv->ptr);
	else if (conv->len == h)
		return ((unsigned short)conv->ptr);
	else if (conv->len == l)
		return ((unsigned long)conv->ptr);
	else if (conv->len == ll)
		return ((unsigned long long)conv->ptr);
	else if (conv->len == j)
		return ((uintmax_t)conv->ptr);
	else if (conv->len == z)
		return ((size_t)conv->ptr);
	else
		return ((unsigned int)conv->ptr);
}

static double		cast_float_nbr(t_conv *conv)
{
	double nbr;

	nbr = *(double*)conv->ptr;
	return (nbr);
}

char				*float_to_str(t_env *env)
{
	char			*new;
	char			*tmp1;
	char			*tmp2;
	long double		nbr;
	long double		tmp;

	nbr = cast_float_nbr(env->conv);
	if (nbr < 0)
	{
		nbr *= -1;
		env->conv->flags->plus = -1;
	}
	tmp1 = ft_itoa_base((intmax_t)nbr, 10);
	tmp = nbr - (intmax_t)nbr;
	while (tmp - (intmax_t)tmp < 0)
		tmp *= 10;
	tmp2 = ft_itoa_base((intmax_t)nbr, 10);
	new = ft_strnew(ft_strlen(tmp1) + ft_strlen(tmp2) + 1);
	new = ft_strcpy(new, tmp1);
	new = ft_strcat(new, ".");
	new = ft_strcat(new, tmp2);
	return (new);
}

char				*nbr_to_str(t_env *env)
{
	char			*new;
	intmax_t		nbr;

	if (env->conv->type == 'd')
	{
		nbr = cast_signed_nbr(env->conv);
		if (nbr < 0)
		{
			nbr *= -1;
			env->conv->flags->plus = -1;
		}
	}
	else
		nbr = cast_unsigned_nbr(env->conv);
	new = NULL;
	if (ft_strchr("du", env->conv->type))
		new = ft_itoa_base((uintmax_t)nbr, 10);
	else if (ft_strchr("oO", env->conv->type))
		new = ft_itoa_base((uintmax_t)nbr, 8);
	else if (ft_strchr("b", env->conv->type))
		new = ft_itoa_base((uintmax_t)nbr, 2);
	else if (ft_strchr("xXp", env->conv->type))
		new = ft_itoa_base((uintmax_t)nbr, 16);
	return (new);
}
