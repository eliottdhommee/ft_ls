/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_normaltobuffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:23:19 by edhommee          #+#    #+#             */
/*   Updated: 2017/06/26 12:23:21 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_env	*get_color(t_env *env)
{
	env->i += 2;
	env = putstr_to_buffer("\033[", env);
	if (env->form[env->i] == 'o')
		env = putchar_to_buffer('1', env);
	else if (env->form[env->i] == 'i')
		env = putchar_to_buffer('2', env);
	else if (env->form[env->i] == 'u')
		env = putchar_to_buffer('4', env);
	else if (ft_strncmp(&env->form[env->i], "eoc", 3))
	{
		if (env->form[env->i] == 'b')
		{
			env = putstr_to_buffer("48;5;", env);
			env->i++;
		}
		else
			env = putstr_to_buffer("38;5;", env);
		while (ft_isdigit(env->form[env->i]))
			env = putchar_to_buffer(env->form[env->i++], env);
	}
	env = putchar_to_buffer('m', env);
	while (env->form[env->i] != '}')
		env->i++;
	env->i++;
	return (env);
}

t_env			*normal_to_buffer(t_env *env)
{
	while (env->form[env->i] && env->form[env->i] != '%')
	{
		if (env->form[env->i] == '{' && env->form[env->i + 1] == '$')
			env = get_color(env);
		env->buf[env->j++] = env->form[env->i++];
		if (env->j == BUFF_SIZE)
		{
			env->ret += print_buffer(env->j, env);
			env->j = 0;
		}
	}
	return (env);
}
