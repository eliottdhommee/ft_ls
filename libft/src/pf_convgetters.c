/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convgetters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:21:51 by edhommee          #+#    #+#             */
/*   Updated: 2017/06/26 12:21:52 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				get_id(t_env *env)
{
	int			start;
	int			res;

	start = env->i;
	res = 0;
	while (ft_isdigit(env->form[env->i]))
		env->i++;
	if (env->form[env->i] == '$')
	{
		env->i++;
		if (env->numbered >= 0)
		{
			env->numbered = 1;
			res = ft_atoi(&env->form[start]);
		}
		else if (env->numbered == -1)
			res = -1;
	}
	else
	{
		env->numbered = -1;
		env->i = start;
		res = ++env->nbarg;
	}
	return (res);
}

t_flags			*get_flags(t_env *env)
{
	t_flags		*new;

	new = NULL;
	new = flagsnew(new);
	while (isflag(env->form[env->i]))
	{
		if (env->form[env->i] == '#')
			new->hash = 1;
		else if (env->form[env->i] == '0')
			new->zero = 1;
		else if (env->form[env->i] == '-')
			new->min = 1;
		else if (env->form[env->i] == ' ')
			new->space = 1;
		else if (env->form[env->i] == '+')
			new->plus = 1;
		else if (env->form[env->i] == '\'')
			new->apos = 1;
		env->i++;
	}
	return (new);
}

int				get_width(va_list *ap, t_env *env)
{
	int			width;
	int			id;

	if (env->form[env->i] == '*')
	{
		env->i++;
		if (env->numbered == -1)
		{
			id = env->conv->id;
			env->conv->id = get_id(env);
		}
		else
			id = get_id(env);
		width = (int)get_arg(id, ap);
	}
	else
	{
		width = ft_atoi(&env->form[env->i]);
		while (ft_isdigit(env->form[env->i]))
			env->i++;
	}
	return (width);
}

int				get_preci(va_list *ap, t_env *env)
{
	int			preci;
	int			id;

	preci = -1;
	if (env->form[++env->i] == '*')
	{
		env->i++;
		if (env->numbered == -1)
		{
			id = env->conv->id;
			env->conv->id = get_id(env);
		}
		else
			id = get_id(env);
		preci = (int)get_arg(id, ap);
	}
	else
	{
		preci = ft_atoi(&env->form[env->i]);
		while (ft_isdigit(env->form[env->i]))
			env->i++;
	}
	return (preci);
}

t_lenght		get_len(t_env *env)
{
	t_lenght	len;

	len = NONE;
	if (env->form[env->i] == 'h')
		len = h;
	else if (env->form[env->i] == 'l')
		len = l;
	else if (env->form[env->i] == 'j')
		len = j;
	else if (env->form[env->i] == 't')
		len = t;
	else if (env->form[env->i] == 'z')
		len = z;
	else if (env->form[env->i] == 'q')
		len = q;
	else if (env->form[env->i] == 'L')
		len = L;
	if (len != NONE && env->form[env->i] == env->form[env->i + 1])
	{
		len = ll;
		if (env->form[env->i++] == 'h')
			len = hh;
	}
	env->i++;
	return (len);
}
