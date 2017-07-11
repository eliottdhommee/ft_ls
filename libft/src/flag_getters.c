/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:27:44 by edhommee          #+#    #+#             */
/*   Updated: 2017/05/21 17:05:52 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			get_id(t_env *env)
{
	int		start;
	int		i;

	i = env->i;
	start = i;
	while (ft_isdigit(env->form[i]) && env->form[i] != '0')
		i++;
	if (env->form[i] == '$')
	{
		env->i = i + 1;
		i = start;
		if (env->numbered >= 0)
		{
			env->numbered = 1;
			return (ft_atoi(&env->form[i]));
		}
		else if (env->numbered == -1)
			return (-1);
	}
	else
		env->numbered = -1;
	return (0);
}

t_flags		*get_flags(t_env *env)
{
	t_flags		*new;

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
		else if (env->form[env->i] == 39)
			new->apos = 1;
		env->i++;
	}
	return (new);
}

int			get_width(t_env *env)
{
	int		width;

	width = ft_atoi(&env->form[env->i]);
	while (ft_isdigit(env->form[env->i]))
		env->i++;
	return (width);
}

int			get_preci(t_env *env)
{
	int		preci;

	preci = 0;
	if (env->form[env->i] == '.')
	{
		env->i++;
		preci = ft_atoi(&env->form[env->i]);
		while (ft_isdigit(env->form[env->i]))
			env->i++;
	}
	return (preci);
}

enum lenght		get_len(t_env *env)
{
	enum lenght		len;

	if (islenght(env->form[env->i]))
	{
		if (env->form[env->i] == 'h')
			len = h;
		if (env->form[env->i] == 'l')
			len = l;
		if (env->form[env->i] == 'j')
			len = j;
		if (env->form[env->i] == 't')
			len = t;
		if (env->form[env->i] == 'z')
			len = z;
		if (env->form[env->i] == 'q')
			len = q;
		if (env->form[env->i] == 'L')
			len = L;
		if (env->form[env->i] == env->form[env->i + 1])
		{
			if (env->form[env->i] == 'h')
				len = hh;
			else
				len = ll;
		}
	}
	return (len);
}
