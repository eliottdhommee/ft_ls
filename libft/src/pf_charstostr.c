/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_charstostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:21:26 by edhommee          #+#    #+#             */
/*   Updated: 2017/06/26 12:21:28 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*str_to_str(t_env *env)
{
	char	*new;
	char	*tmp;

	new = NULL;
	if (env->conv->type == '%')
		new = ft_strdup("%");
	else if (env->conv->type == 'c')
	{
		new = ft_strnew(1);
		new[0] = (char)env->conv->ptr;
	}
	else
	{
		tmp = (char*)env->conv->ptr;
		if (!tmp)
			new = ft_strdup("(null)");
		else
			new = ft_strdup(tmp);
	}
	return (new);
}

static int	countwstr(wchar_t *wstr)
{
	int		i;
	int		e;

	e = 0;
	i = 0;
	if (!wstr)
		return (0);
	while (wstr[i])
	{
		if (wstr[i] <= 0x7F)
			e++;
		else if (wstr[i] <= 0x7FF)
			e = e + 2;
		else if (wstr[i] <= 0xFFFF)
			e = e + 3;
		else if (wstr[i] <= 0x10FFFF)
			e = e + 4;
		i++;
	}
	return (e);
}

static char	*wchar_to_str(wchar_t *wstr)
{
	int		i;
	char	*new;
	char	*tmp;

	i = 0;
	new = NULL;
	if (!wstr)
		new = ft_strdup("(null)");
	else
	{
		new = ft_strnew((countwstr(wstr) + 1));
		while (wstr[i])
		{
			tmp = ft_wchartoa(wstr[i++]);
			new = ft_strcat(new, tmp);
			ft_strdel(&tmp);
		}
	}
	return (new);
}

char		*chars_to_str(t_env *env)
{
	char	*new;

	new = NULL;
	if (env->conv->len != l)
		new = str_to_str(env);
	else if (env->conv->type == 's')
		new = wchar_to_str((wchar_t*)env->conv->ptr);
	else if (env->conv->type == 'c')
		new = ft_wchartoa((wint_t)env->conv->ptr);
	return (new);
}
