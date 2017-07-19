/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buffering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:21:04 by edhommee          #+#    #+#             */
/*   Updated: 2017/06/26 12:21:06 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_buffer(int size, t_env *env)
{
	return (write(env->fd, env->buf, size));
}

t_env	*putchar_to_buffer(char c, t_env *env)
{
	env->buf[env->j++] = c;
	if (env->j == BUFF_SIZE)
	{
		env->ret += print_buffer(BUFF_SIZE, env);
		env->j = 0;
	}
	return (env);
}

t_env	*putstr_to_buffer(char *str, t_env *env)
{
	int	i;

	i = 0;
	while (str[i])
	{
		env->buf[env->j++] = str[i++];
		if (env->j == BUFF_SIZE)
		{
			env->ret += print_buffer(BUFF_SIZE, env);
			env->j = 0;
		}
	}
	return (env);
}
